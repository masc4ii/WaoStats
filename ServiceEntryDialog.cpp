#include "ServiceEntryDialog.h"
#include "ui_ServiceEntryDialog.h"
#include <QDebug>

ServiceEntryDialog::ServiceEntryDialog(QWidget *parent, QString part, QString description, QString actionText, QDateTime dateTime):
    QDialog(parent),
    ui(new Ui::ServiceEntryDialog)
{
    ui->setupUi(this);
    //ui->dateTimeEdit->setDateTime( dateTime );
    ui->calendarWidget->setSelectedDate( dateTime.date() );
    ui->timeEdit->setTime( dateTime.time() );
    ui->lineEditPart->setText( part );
    ui->comboBoxAction->setCurrentText( actionText );
    ui->lineEditDescr->setText( description );
}

ServiceEntryDialog::~ServiceEntryDialog()
{
    delete ui;
}

QString ServiceEntryDialog::part()
{
    return ui->lineEditPart->text();
}

QString ServiceEntryDialog::description()
{
    return ui->lineEditDescr->text();
}

QString ServiceEntryDialog::actionText()
{
    return ui->comboBoxAction->currentText();
}

QDateTime ServiceEntryDialog::dateTime()
{
    //return ui->dateTimeEdit->dateTime();
    return QDateTime( ui->calendarWidget->selectedDate(), ui->timeEdit->time() );
}

void ServiceEntryDialog::on_pushButtonNow_clicked()
{
    //ui->dateTimeEdit->setDateTime( QDateTime::currentDateTime() );
    ui->calendarWidget->setSelectedDate( QDate::currentDate() );
    ui->timeEdit->setTime( QTime::currentTime() );
}

void ServiceEntryDialog::on_buttonBox_accepted()
{
    accept();
}

void ServiceEntryDialog::on_buttonBox_rejected()
{
    reject();
}

