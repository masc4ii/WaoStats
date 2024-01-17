#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include <QMutex>
#include <QTimerEvent>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = nullptr, int jobs = 1, QMutex *pMutex = nullptr, uint32_t *pTodo = nullptr);
    ~ProgressDialog();
    void setActionText( QString text );
    void setTitle( QString text );
    bool wasRejected( void );

private slots:
    void on_pushButtonAbort_clicked();

private:
    void timerEvent(QTimerEvent *t );
    Ui::ProgressDialog *ui;
    int m_jobs;
    QMutex *m_pMutex;
    uint32_t *m_pTodo;
    int m_timerId;
    QString m_actionText = QString( "tracks analyzed" );
    bool m_wasRejected = false;
};

#endif // PROGRESSDIALOG_H
