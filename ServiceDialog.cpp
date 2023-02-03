#include "ServiceDialog.h"
#include "ui_ServiceDialog.h"

#include <QDateTime>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

ServiceDialog::ServiceDialog(QWidget *parent, QTreeWidget *tree) :
    QDialog(parent),
    ui(new Ui::ServiceDialog),
    m_tourTree( tree )
{
    ui->setupUi(this);

    if( m_tourTree == nullptr ) return;

    for( int i = 0; i < m_tourTree->topLevelItemCount(); i++ )
    {
        if( "New" == m_tourTree->topLevelItem( i )->text( 0 ) ) continue;
        ui->comboBoxBike->addItem( m_tourTree->topLevelItem( i )->text( 0 )
                                   + " ("
                                   + m_tourTree->topLevelItem( i )->text( 2 )
                                   + ")" );
    }

    loadFromJson();
}

ServiceDialog::~ServiceDialog()
{
    delete ui;
}

void ServiceDialog::on_pushButtonClose_clicked()
{
    close();
}

void ServiceDialog::on_pushButtonAdd_clicked()
{
    ServiceEntryDialog *entryDialog = new ServiceEntryDialog( this );
    if( QDialog::Accepted == entryDialog->exec() )
    {
        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
        for( int i = 0; i < ui->tableWidget->columnCount(); i++ )
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setFlags( item->flags() & ~Qt::EditRole );
            ui->tableWidget->setItem( ui->tableWidget->rowCount() - 1, i, item );
        }

        fillTableRow( entryDialog, ui->tableWidget->rowCount() - 1 );
        updateOdoInUseColumn();
        writeToJson();
    }
    delete entryDialog;
}

void ServiceDialog::on_pushButtonDelete_clicked()
{
    if( ui->tableWidget->selectedItems().empty() || ui->tableWidget->selectedItems().first()->row() < 0 ) return;
    ui->tableWidget->removeRow( ui->tableWidget->selectedItems().first()->row() );
    writeToJson();
}

void ServiceDialog::on_tableWidget_cellDoubleClicked(int row, int column)
{
    Q_UNUSED( column );
    ServiceEntryDialog *entryDialog = new ServiceEntryDialog( this,
                                                              ui->tableWidget->item( row, 3 )->text(),
                                                              ui->tableWidget->item( row, 5 )->text(),
                                                              ui->tableWidget->item( row, 4 )->text(),
                                                              QDateTime::fromString( ui->tableWidget->item( row, 0 )->text(),
                                                                                     QString( "yyyy-MM-dd - hh:mm" ) ) );
    if( QDialog::Accepted == entryDialog->exec() )
    {
        fillTableRow( entryDialog, row );
        updateOdoInUseColumn();
        writeToJson();
    }
    delete entryDialog;
}

void ServiceDialog::fillTableRow(ServiceEntryDialog *entryDialog, int row)
{
    ui->tableWidget->item( row, 0 )->setText( entryDialog->dateTime().toString( "yyyy-MM-dd - hh:mm" ) );
    ui->tableWidget->item( row, 1 )->setText( QString( "%1 km" ).arg( odoAtDateTime( entryDialog->dateTime() ), 0, 'f', 0 ) );
    ui->tableWidget->item( row, 2 )->setText( QString::number( 0 ) + " km" );
    ui->tableWidget->item( row, 3 )->setText( entryDialog->part() );
    ui->tableWidget->item( row, 4 )->setText( entryDialog->actionText() );
    ui->tableWidget->item( row, 5 )->setText( entryDialog->description() );
    ui->tableWidget->sortByColumn( 0, Qt::DescendingOrder );
}

double ServiceDialog::odoAtDateTime(QDateTime dateTime)
{
    int topItem = ui->comboBoxBike->currentIndex();
    double odoTotal = m_tourTree->topLevelItem(topItem)->text(3).toDouble();

    for( int i = 0; i < m_tourTree->topLevelItem(topItem)->childCount(); i++ )
    {
        if( QDateTime().fromString( m_tourTree->topLevelItem(topItem)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) > dateTime )
        {
            odoTotal -= m_tourTree->topLevelItem(topItem)->child(i)->text(3).toDouble();
        }
        else
        {
            return odoTotal;
        }
    }
    return odoTotal;
}

double ServiceDialog::odoInUse(int row)
{
    int topItem = ui->comboBoxBike->currentIndex();
    double odoTotal1 = m_tourTree->topLevelItem(topItem)->text(3).toDouble();
    double odoTotal2 = m_tourTree->topLevelItem(topItem)->text(3).toDouble();

    QDateTime dateTime1 = QDateTime().fromString( ui->tableWidget->item( row, 0 )->text(), "yyyy-MM-dd - hh:mm" );
    QString part = ui->tableWidget->item( row, 3 )->text();
    int row2 = -1;

    //2nd entry availlable?
    for( int i = 0; i < row; i++ )
    {
        if( part == ui->tableWidget->item( i, 3 )->text() ) row2 = i;
    }

    //Original distance
    for( int i = 0; i < m_tourTree->topLevelItem(topItem)->childCount(); i++ )
    {
        if( QDateTime().fromString( m_tourTree->topLevelItem(topItem)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) > dateTime1 )
        {
            odoTotal1 -= m_tourTree->topLevelItem(topItem)->child(i)->text(3).toDouble();
        }
        else
        {
            break;
        }
    }

    //2nd distance
    if( row2 > -1 )
    {
        QDateTime dateTime2 = QDateTime().fromString( ui->tableWidget->item( row2, 0 )->text(), "yyyy-MM-dd - hh:mm" );
        for( int i = 0; i < m_tourTree->topLevelItem(topItem)->childCount(); i++ )
        {
            if( QDateTime().fromString( m_tourTree->topLevelItem(topItem)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) > dateTime2 )
            {
                odoTotal2 -= m_tourTree->topLevelItem(topItem)->child(i)->text(3).toDouble();
            }
            else
            {
                break;
            }
        }
    }

    //Difference
    return odoTotal2 - odoTotal1;
}

void ServiceDialog::updateOdoInUseColumn()
{
    for( int i = 0; i < ui->tableWidget->rowCount(); i++ )
    {
        ui->tableWidget->item( i, 2 )->setText( QString( "%1 km" ).arg( (int)( odoInUse( i ) + 0.5f ) ) );
    }
}

void ServiceDialog::writeToJson()
{
    QJsonObject services;
    QJsonObject info;
    for( int row = 0; row < ui->tableWidget->rowCount(); row++ )
    {
        info.insert( "dateTime",    ui->tableWidget->item( row, 0 )->text() );
        info.insert( "part",        ui->tableWidget->item( row, 3 )->text() );
        info.insert( "action",      ui->tableWidget->item( row, 4 )->text() );
        info.insert( "description", ui->tableWidget->item( row, 5 )->text() );
        services.insert( QString::number( row ), info );
    }
    QJsonDocument doc( services );
    //write json doc into file
    QString fileName = QString( "%1/%2" ).arg( m_tourTree->topLevelItem( ui->comboBoxBike->currentIndex() )->text(1) ).arg( "service.json" );
    QFile file( fileName );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        //Try to write the JSON document
        file.write( doc.toJson() );
        file.close();
    }
}

void ServiceDialog::loadFromJson()
{
    //ui->tableWidget->clear(); //doesn't work, whyever
    int rowCnt = ui->tableWidget->rowCount();
    for( int i = 0; i < rowCnt; i++ ) ui->tableWidget->removeRow( 0 );

    //Read file
    QString fileName = QString( "%1/%2" ).arg( m_tourTree->topLevelItem( ui->comboBoxBike->currentIndex() )->text(1) ).arg( "service.json" );
    QFile file( fileName );
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        //qDebug() << "open service.json file failed.";
        return;
    }
    QJsonDocument doc = QJsonDocument::fromJson( file.readAll() );
    file.close();

    //JSON is invalid
    if( doc.isNull() )
    {
        qDebug() << "service.json file invalid.";
        return;
    }

    for( int i = 0; i < doc.object().count(); i++ )
    {
        QJsonObject info = doc.object().value( QString( "%1" ).arg( i ) ).toObject();

        ServiceEntryDialog *entryDialog = new ServiceEntryDialog( this,
                                                                  info.value( "part" ).toString(),
                                                                  info.value( "description" ).toString(),
                                                                  info.value( "action" ).toString(),
                                                                  QDateTime::fromString( info.value( "dateTime" ).toString(),
                                                                                         QString( "yyyy-MM-dd - hh:mm" ) ) );
        ui->tableWidget->insertRow( i );
        for( int j = 0; j < ui->tableWidget->columnCount(); j++ )
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setFlags( item->flags() & ~Qt::EditRole );
            ui->tableWidget->setItem( i, j, item );
        }

        fillTableRow( entryDialog, i );
        delete entryDialog;
    }
    updateOdoInUseColumn();
}

void ServiceDialog::on_comboBoxBike_currentIndexChanged(int index)
{
    Q_UNUSED( index );
    loadFromJson();
}
