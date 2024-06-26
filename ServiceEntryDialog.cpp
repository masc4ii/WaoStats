#include "ServiceEntryDialog.h"
#include "ui_ServiceEntryDialog.h"
#include <QDebug>
#include <QCompleter>

ServiceEntryDialog::ServiceEntryDialog(QWidget *parent, QStringList partList, QString part, QString description, QString actionText, QDateTime dateTime, int intervalDistance, int intervalTime, QTime costsT, double costsM):
    QDialog(parent),
    ui(new Ui::ServiceEntryDialog)
{
    ui->setupUi(this);

    QCompleter *completer = new QCompleter( partList, this );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    ui->lineEditPart->setCompleter( completer );

    if( partList.isEmpty() && part.isEmpty() )
    {
        ui->lineEditPart->setText( "Chain" );
        ui->lineEditDescr->setText( "Replaced with brand xy" );
    }
    else
    {
        ui->lineEditPart->setText( part );
        ui->lineEditDescr->setText( description );
    }
    ui->calendarWidget->setSelectedDate( dateTime.date() );
    ui->timeEdit->setTime( dateTime.time() );
    ui->comboBoxAction->setCurrentText( actionText );
    ui->spinBoxIntervalDist->setValue( intervalDistance );
    ui->spinBoxIntervalTime->setValue( intervalTime );
    ui->timeEditCostsT->setTime( costsT );
    ui->doubleSpinBoxIntervalCostsM->setValue( costsM );

    ui->labelAction->setHidden( true );
    ui->comboBoxAction->setHidden( true );
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

int ServiceEntryDialog::intervalDistance()
{
    return ui->spinBoxIntervalDist->value();
}

int ServiceEntryDialog::intervalHours()
{
    return ui->spinBoxIntervalTime->value();
}

double ServiceEntryDialog::costsM()
{
    return ui->doubleSpinBoxIntervalCostsM->value();
}

QTime ServiceEntryDialog::costsT()
{
    return ui->timeEditCostsT->time();
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

