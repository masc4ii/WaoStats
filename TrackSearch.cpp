#include "TrackSearch.h"
#include "ui_ProgressDialog.h"

TrackSearch::TrackSearch(QWidget *parent, int jobs, QMutex *pMutex, uint32_t *pTodo) :
    ProgressDialog(parent),
    m_jobs(jobs),
    m_pMutex(pMutex),
    m_pTodo(pTodo)
{
    if( m_pTodo == nullptr || m_pMutex == nullptr )
    {
        reject();
        return;
    }
    m_timerId = startTimer( 100 );
    setTitle( "Search Tracks..." );
    setActionText(QString( "tracks analyzed" ));
}

TrackSearch::~TrackSearch()
{
    killTimer( m_timerId );
}

void TrackSearch::timerEvent(QTimerEvent *t)
{
    if( t->timerId() == m_timerId )
    {
        m_pMutex->lock();
        int todo = *m_pTodo;
        m_pMutex->unlock();
        if( todo == 0 )
        {
            accept();
            return;
        }
        if( m_retVal == RetReject ) reject();
        ui->progressBar->setValue( 100 * ( (double)m_jobs - (double)todo ) / (double)m_jobs );
        ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( m_jobs - todo ).arg( m_jobs ).arg( m_actionText ) );
    }
}

