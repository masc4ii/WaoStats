#include "AdbSelectDeviceDialog.h"
#include "ui_AdbSelectDeviceDialog.h"
#include <QProcess>
#include <QTableWidgetItem>
#include <QDebug>
#include "AdbWrapper.h"

AdbSelectDeviceDialog::AdbSelectDeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdbSelectDeviceDialog)
{
    ui->setupUi(this);
    scan();
}

AdbSelectDeviceDialog::~AdbSelectDeviceDialog()
{
    delete ui;
}

QString AdbSelectDeviceDialog::selectedDeviceId()
{
    if( !ui->tableWidget->rowCount() ) return "";
    else return ui->tableWidget->selectedItems().at( 0 )->text();
}

void AdbSelectDeviceDialog::on_pushButtonRefresh_clicked()
{
    scan();
}

void AdbSelectDeviceDialog::scan()
{
    while( ui->tableWidget->rowCount() ) ui->tableWidget->removeRow( 0 );

    AdbWrapper *adbWrap = new AdbWrapper( this );
    QStringList deviceList = adbWrap->deviceList();
    delete adbWrap;

    foreach( QString device, deviceList )
    {
        QString serial = device;
        serial = serial.left( serial.indexOf( " " ) );

        QString model = device;
        if( model.contains( "model:" ) )
        {
            model = model.right( model.size() - model.indexOf( "model:" ) - 6 );
            model = model.left( model.indexOf( " " ) );
        }
        else
        {
            model = "unauthorized";
        }

        //qDebug() << serial << model;
        QTableWidgetItem *item1 = new QTableWidgetItem( serial );
        QTableWidgetItem *item2 = new QTableWidgetItem( model );

        ui->tableWidget->setRowCount( ui->tableWidget->rowCount() + 1 );
        ui->tableWidget->setItem( ui->tableWidget->rowCount() - 1, 0, item1 );
        ui->tableWidget->setItem( ui->tableWidget->rowCount() - 1, 1, item2 );
    }

    if( ui->tableWidget->rowCount() ) ui->tableWidget->selectRow( 0 );
    ui->pushButtonOk->setEnabled( ui->tableWidget->rowCount() );
}
