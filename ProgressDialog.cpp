#include "ProgressDialog.h"
#include "ui_ProgressDialog.h"

ProgressDialog::ProgressDialog(QWidget *parent, int jobs, QMutex *pMutex, uint32_t *pTodo) :
    QDialog(parent),
    ui(new Ui::ProgressDialog),
    m_jobs(jobs),
    m_pMutex(pMutex),
    m_pTodo(pTodo)
{
    ui->setupUi(this);
    setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    if( m_pTodo == nullptr || m_pMutex == nullptr )
    {
        reject();
        return;
    }
    m_timerId = startTimer( 100 );
    ui->progressBar->setValue( 0 );
}

ProgressDialog::~ProgressDialog()
{
    killTimer( m_timerId );
    delete ui;
}

void ProgressDialog::setActionText(QString text)
{
    m_actionText = text;
}

void ProgressDialog::setTitle(QString text)
{
    setWindowTitle( text );
}

bool ProgressDialog::wasRejected()
{
    return m_wasRejected;
}

void ProgressDialog::on_pushButtonAbort_clicked()
{
    m_wasRejected = true;
    reject();
}

void ProgressDialog::timerEvent(QTimerEvent *t)
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
        ui->progressBar->setValue( 100 * ( (double)m_jobs - (double)todo ) / (double)m_jobs );
        ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( m_jobs - todo ).arg( m_jobs ).arg( m_actionText ) );
    }
}

