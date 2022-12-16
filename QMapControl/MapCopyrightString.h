#ifndef MAPCOPYRIGHTSTRING_H
#define MAPCOPYRIGHTSTRING_H

#include <QString>

class MapCopyrightString
{
protected:
    // Static variable for the one-and-only instance
    static MapCopyrightString* m_pInstance;
    QString m_copyRightText;

public:
    // Returns a reference to the singleton Logger object
    static MapCopyrightString* instance();
    void setCopyright( QString text ){ m_copyRightText = text; }
    QString copyright( void );

private:
    MapCopyrightString() : m_copyRightText("") {} // private constructor
};

#endif // MAPCOPYRIGHTSTRING_H
