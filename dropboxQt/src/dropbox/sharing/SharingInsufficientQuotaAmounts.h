/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class InsufficientQuotaAmounts{
        /**
            field: space_needed: The amount of space needed to add the item (the
                size of the item).
            field: space_shortage: The amount of extra space needed to add the
                item.
            field: space_left: The amount of space left in the user's Dropbox,
                less than space_needed.
        */

    public:
        InsufficientQuotaAmounts(){};

        InsufficientQuotaAmounts(const int& arg){ m_space_needed = arg; };
        virtual ~InsufficientQuotaAmounts(){};

    public:
            /**
                The amount of space needed to add the item (the size of the
                item).
            */
        int spaceNeeded()const{return m_space_needed;};
        InsufficientQuotaAmounts& setSpaceneeded(const int& arg){m_space_needed=arg;return *this;};

            /**
                The amount of extra space needed to add the item.
            */
        int spaceShortage()const{return m_space_shortage;};
        InsufficientQuotaAmounts& setSpaceshortage(const int& arg){m_space_shortage=arg;return *this;};

            /**
                The amount of space left in the user's Dropbox, less than
                space_needed.
            */
        int spaceLeft()const{return m_space_left;};
        InsufficientQuotaAmounts& setSpaceleft(const int& arg){m_space_left=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<InsufficientQuotaAmounts>  create(const QByteArray& data);
            static std::unique_ptr<InsufficientQuotaAmounts>  create(const QJsonObject& js);
        };



    protected:
            /**
                The amount of space needed to add the item (the size of the
                item).
            */
        int m_space_needed = {0};

            /**
                The amount of extra space needed to add the item.
            */
        int m_space_shortage = {0};

            /**
                The amount of space left in the user's Dropbox, less than
                space_needed.
            */
        int m_space_left = {0};

    };//InsufficientQuotaAmounts

}//sharing
}//dropboxQt
