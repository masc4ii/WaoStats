#include "MapCopyrightString.h"
#include <QDateTime>

MapCopyrightString *MapCopyrightString::m_pInstance = nullptr;

MapCopyrightString *MapCopyrightString::instance()
{
    if (m_pInstance == nullptr)
        m_pInstance = new MapCopyrightString();
    return m_pInstance;
}

QString MapCopyrightString::copyright()
{
    return QString( "© %1 %2" ).arg( QDateTime::currentDateTime().toString( "yyyy" ) ).arg( m_copyRightText );
}
