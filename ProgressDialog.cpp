#include "ProgressDialog.h"
#include "ui_ProgressDialog.h"

ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    ui->progressBar->setValue( 0 );
}

ProgressDialog::~ProgressDialog()
{
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

ProgressDialog::eProgressReturn ProgressDialog::downloadResult()
{
    return m_retVal;
}

void ProgressDialog::on_pushButtonAbort_clicked()
{
    m_retVal = RetReject;
}

