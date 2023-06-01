#ifndef THREADTRACK2POINT_H
#define THREADTRACK2POINT_H

#include <QRunnable>
#include <QString>
#include <QTreeWidgetItem>
#include <QThreadPool>
#include <QMutex>

class ThreadTrack2Point : public QRunnable
{
public:
    ThreadTrack2Point( double latitude, double longitude, QMutex *mutex = nullptr, uint32_t *cnt = nullptr, QTreeWidgetItem *item = nullptr );
    void run( void ) override;

protected:
    void decrementThreadCnt( void );
    QTreeWidgetItem *m_pItem;
    QMutex *m_pMutex;
    uint32_t *m_pCnt;
    double m_latitude;
    double m_longitude;
};

#endif // THREADTRACK2POINT_H
