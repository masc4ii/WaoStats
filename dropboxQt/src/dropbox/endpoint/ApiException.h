#pragma once

#include <exception>
#include <string>
#include <memory>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace dropboxQt{
    class DropboxException: public std::exception
    {
    public:
        explicit DropboxException(const std::string& message) :m_msg(message), m_status_code(0){}

        explicit DropboxException(const std::string& message, int code):
            m_msg(message),
            m_status_code(code)
        {};        
        
        explicit DropboxException(const std::string& message, int code, const std::string summary):
            m_msg(message), m_status_code(code), m_error_summary(summary) {
            build("");
        };

        virtual const char* what() const throw (){
            return m_what.c_str();
        }

        virtual int statusCode()const throw(){
            return m_status_code;
        }

        const std::string& errSummary()const { return m_error_summary; }
        
        static  std::unique_ptr<DropboxException> create(const QByteArray& data, int status_code, const std::string& message);
        template<class E, class F>
        static std::unique_ptr<E> createSpecialized(const QByteArray& data, int status_code, const std::string& message) 
        {
            F err; 
            std::string summary;
            if (!data.isEmpty())
                {
                    QJsonDocument doc = QJsonDocument::fromJson(data);
                    QJsonObject js_in = doc.object();
                    err.fromJson(js_in["error"].toObject());
                    summary = js_in["error_summary"].toString().toStdString();
                }
            return std::unique_ptr<E>(new E(err, summary, status_code, message));
        };

        ///Polymorphic exception idiom
        virtual void raise() { throw *this; }

    protected:
        void build(std::string err);

    protected:
        std::string m_msg;
        int m_status_code;
        std::string m_error_summary;
        std::string m_what;
    };

    class IllegalStateException: public DropboxException
    {
    public:
        explicit IllegalStateException(const std::string& message, int state):
            DropboxException(message, state)
        {};
        void raise()override { throw *this; }
    };


#define DECLARE_API_ERR_EXCEPTION(E, F)     class E: public DropboxException{ \
    public:                                                             \
    const F& err()const {return m_err;}                                 \
    void raise()override { throw *this; }                               \
    static std::unique_ptr<E> create(const QByteArray& data, int status_code, const std::string& message); \
    E(const F& err, const std::string& summary, int status_code, const std::string& message); \
    protected:                                                          \
    F m_err;                                                            \
    };                                                                  \


#define IMPLEMENT_API_ERR_EXCEPTION(E, F) E::E(const F& err, const std::string& summary, int status_code, const std::string& message) \
        :DropboxException(message, status_code, summary), m_err(err){   \
    build(m_err.toString().toStdString());                              \
}                                                                       \
        std::unique_ptr<E> E::create(const QByteArray& data, int status_code, const std::string& message) \
        {                                                               \
    return createSpecialized<E, F>(data, status_code, message);         \
}                                                                       \


};
