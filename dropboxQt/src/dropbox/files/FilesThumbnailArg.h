/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesThumbnailFormat.h"
#include "dropbox/files/FilesThumbnailSize.h"

namespace dropboxQt{
namespace files{
    class ThumbnailArg{
        /**
            field: path: The path to the image file you want to thumbnail.
            field: format: The format for the thumbnail image, jpeg (default) or
                png. For  images that are photos, jpeg should be preferred,
                while png is  better for screenshots and digital arts.
            field: size: The size for the thumbnail image.
        */

    public:
        ThumbnailArg():
        m_format(ThumbnailFormat::ThumbnailFormat_JPEG)
        ,m_size(ThumbnailSize::ThumbnailSize_W64H64)
        {};

        ThumbnailArg(const QString& arg):
        m_format(ThumbnailFormat::ThumbnailFormat_JPEG)
        ,m_size(ThumbnailSize::ThumbnailSize_W64H64)
        { m_path = arg; };
        virtual ~ThumbnailArg(){};

    public:
            /**
                The path to the image file you want to thumbnail.
            */
        QString path()const{return m_path;};
        ThumbnailArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                The format for the thumbnail image, jpeg (default) or png. For
                images that are photos, jpeg should be preferred, while png is
                better for screenshots and digital arts.
            */
        const ThumbnailFormat& format()const{return m_format;};
        ThumbnailArg& setFormat(const ThumbnailFormat& arg){m_format=arg;return *this;};

            /**
                The size for the thumbnail image.
            */
        const ThumbnailSize& size()const{return m_size;};
        ThumbnailArg& setSize(const ThumbnailSize& arg){m_size=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ThumbnailArg>  create(const QByteArray& data);
            static std::unique_ptr<ThumbnailArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path to the image file you want to thumbnail.
            */
        QString m_path;

            /**
                The format for the thumbnail image, jpeg (default) or png. For
                images that are photos, jpeg should be preferred, while png is
                better for screenshots and digital arts.
            */
        ThumbnailFormat m_format;

            /**
                The size for the thumbnail image.
            */
        ThumbnailSize m_size;

    };//ThumbnailArg

}//files
}//dropboxQt
