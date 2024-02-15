#pragma once

#include "ProgressDialog.h"
#include <QMutex>
#include <QTimerEvent>

class TrackSearch : public ProgressDialog
{
    Q_OBJECT

public:
    explicit TrackSearch(QWidget *parent = nullptr, int jobs = 1, QMutex *pMutex = nullptr, uint32_t *pTodo = nullptr);
    ~TrackSearch();

private:
    void timerEvent(QTimerEvent *t );
    int m_jobs;
    QMutex *m_pMutex;
    uint32_t *m_pTodo;
    int m_timerId;
};
