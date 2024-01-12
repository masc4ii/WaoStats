#include "ServiceDialog.h"
#include "ui_ServiceDialog.h"

#include <QDateTime>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QListView>

#define DATETIME  0
#define ODOTOTAL  1
#define ODOINUSE  2
#define ODOINTER  3
#define TIMETOTAL 4
#define TIMEINUSE 5
#define TIMEINTER 6
#define PARTNAME  7
#define ACTION    8
#define DESCRIPT  9

ServiceDialog::ServiceDialog(QWidget *parent, QTreeWidget *tree) :
    QDialog(parent),
    ui(new Ui::ServiceDialog),
    m_tourTree( tree )
{
    ui->setupUi(this);

    if( m_tourTree == nullptr ) return;

    for( int i = 0; i < m_tourTree->topLevelItemCount(); i++ )
    {
        //if( "New" == m_tourTree->topLevelItem( i )->text( 0 ) ) continue;
        ui->comboBoxBike->addItem( m_tourTree->topLevelItem( i )->text( 0 )
                                   + " ("
                                   + m_tourTree->topLevelItem( i )->text( 2 )
                                   + ")" );
        if( "New" == m_tourTree->topLevelItem( i )->text( 0 ) )
        {
            qobject_cast<QListView *>(ui->comboBoxBike->view())->setRowHidden(i, true);
        }

        //Select the bike which was selected in main frame
        if( m_tourTree->topLevelItem( i )->isSelected() ) ui->comboBoxBike->setCurrentIndex( i );
        else
        {
            for( int j = 0; j < m_tourTree->topLevelItem( i )->childCount(); j++ )
            {
                if( m_tourTree->topLevelItem( i )->child( j )->isSelected() ) ui->comboBoxBike->setCurrentIndex( i );
            }
        }
    }

    ui->tableWidget->setColumnHidden( ACTION, true );

    ui->tableWidget->setColumnWidth( DATETIME , 120 );
    ui->tableWidget->setColumnWidth( ODOTOTAL , 80 );
    ui->tableWidget->setColumnWidth( ODOINUSE , 80 );
    ui->tableWidget->setColumnWidth( ODOINTER , 80 );
    ui->tableWidget->setColumnWidth( TIMETOTAL, 80 );
    ui->tableWidget->setColumnWidth( TIMEINUSE, 80 );
    ui->tableWidget->setColumnWidth( TIMEINTER, 80 );

    loadFromJson( ui->comboBoxBike->currentIndex() );
}

ServiceDialog::~ServiceDialog()
{
    delete ui;
}

bool ServiceDialog::bikeNeedsService( int index )
{
    loadFromJson( index );
    for( int i = 0; i < ui->tableWidget->rowCount(); i++ )
    {
        if( ui->tableWidget->item( i, ODOINTER )->text().chopped( 3 ).toInt()
         <= ui->tableWidget->item( i, ODOINUSE )->text().chopped( 3 ).toInt()
         && ui->tableWidget->item( i, ODOINTER )->text().chopped( 3 ).toInt() != 0 )
        {
            return true;
        }
        if( ui->tableWidget->item( i, TIMEINTER )->text().chopped( 2 ).toInt()
         <= ui->tableWidget->item( i, TIMEINUSE )->text().leftRef( ui->tableWidget->item( i, TIMEINUSE )->text().indexOf( ":" ) ).toInt()
         && ui->tableWidget->item( i, TIMEINTER )->text().chopped( 2 ).toInt() != 0 )
        {
            return true;
        }
    }
    return false;
}

void ServiceDialog::on_pushButtonClose_clicked()
{
    close();
}

void ServiceDialog::on_pushButtonAdd_clicked()
{
    ServiceEntryDialog *entryDialog = new ServiceEntryDialog( this, partList() );
    if( QDialog::Accepted == entryDialog->exec() )
    {
        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
        for( int i = 0; i < ui->tableWidget->columnCount(); i++ )
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setFlags( item->flags() & ~Qt::EditRole );
            ui->tableWidget->setItem( ui->tableWidget->rowCount() - 1, i, item );
        }

        fillTableRow( entryDialog, ui->tableWidget->rowCount() - 1, ui->comboBoxBike->currentIndex() );
        updateOdoInUseColumn( ui->comboBoxBike->currentIndex() );
        updateSecsInUseColumn( ui->comboBoxBike->currentIndex() );
        updateCellColor();
        writeToJson( ui->comboBoxBike->currentIndex() );
    }
    delete entryDialog;
}

void ServiceDialog::on_pushButtonDelete_clicked()
{
    if( ui->tableWidget->selectedItems().empty() || ui->tableWidget->selectedItems().first()->row() < 0 ) return;
    ui->tableWidget->removeRow( ui->tableWidget->selectedItems().first()->row() );

    updateOdoInUseColumn( ui->comboBoxBike->currentIndex() );
    updateSecsInUseColumn( ui->comboBoxBike->currentIndex() );
    updateCellColor();
    writeToJson( ui->comboBoxBike->currentIndex() );
}

void ServiceDialog::on_tableWidget_cellDoubleClicked(int row, int column)
{
    Q_UNUSED( column );
    ServiceEntryDialog *entryDialog = new ServiceEntryDialog( this,
                                                              partList(),
                                                              ui->tableWidget->item( row, PARTNAME )->text(),
                                                              ui->tableWidget->item( row, DESCRIPT )->text(),
                                                              ui->tableWidget->item( row, ACTION )->text(),
                                                              QDateTime::fromString( ui->tableWidget->item( row, DATETIME )->text(),
                                                                                     QString( "yyyy-MM-dd - hh:mm" ) ),
                                                              ui->tableWidget->item( row, ODOINTER )->text().chopped( 3 ).toInt(),
                                                              ui->tableWidget->item( row, TIMEINTER )->text().chopped( 2 ).toInt() );
    if( QDialog::Accepted == entryDialog->exec() )
    {
        fillTableRow( entryDialog, row, ui->comboBoxBike->currentIndex() );
        updateOdoInUseColumn( ui->comboBoxBike->currentIndex() );
        updateSecsInUseColumn( ui->comboBoxBike->currentIndex() );
        updateCellColor();
        writeToJson( ui->comboBoxBike->currentIndex() );
    }
    delete entryDialog;
}

void ServiceDialog::fillTableRow(ServiceEntryDialog *entryDialog, int row, int index)
{
    ui->tableWidget->item( row, DATETIME )->setText( entryDialog->dateTime().toString( "yyyy-MM-dd - hh:mm" ) );
    ui->tableWidget->item( row, ODOTOTAL )->setText( QString( "%1 km" ).arg( odoAtDateTime( entryDialog->dateTime(), index ), 0, 'f', 0 ) );
    ui->tableWidget->item( row, ODOINUSE )->setText( QString::number( 0 ) + " km" );
    ui->tableWidget->item( row, ODOINTER )->setText( QString::number( entryDialog->intervalDistance() ) + " km" );
    ui->tableWidget->item( row, TIMETOTAL )->setText( QString( "%1:%2" ).arg( (int)(secsAtDateTime( entryDialog->dateTime(), index )/3600), 2, 'f', 0, '0' ).arg( QTime(0,0).addSecs( secsAtDateTime( entryDialog->dateTime(), index ) ).toString( "mm:ss" ) ) );
    ui->tableWidget->item( row, TIMEINUSE )->setText( QString( "00:00:00" ) );
    ui->tableWidget->item( row, TIMEINTER )->setText( QString::number( entryDialog->intervalHours() ) + " h" );
    ui->tableWidget->item( row, PARTNAME )->setText( entryDialog->part() );
    //ui->tableWidget->item( row, ACTION )->setText( entryDialog->actionText() );
    ui->tableWidget->item( row, DESCRIPT )->setText( entryDialog->description() );
    ui->tableWidget->sortByColumn( 0, Qt::DescendingOrder );
}

double ServiceDialog::odoAtDateTime(QDateTime dateTime, int index)
{
    double odoTotal = m_tourTree->topLevelItem(index)->text(3).toDouble();

    for( int i = 0; i < m_tourTree->topLevelItem(index)->childCount(); i++ )
    {
        if( QDateTime().fromString( m_tourTree->topLevelItem(index)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) > dateTime )
        {
            odoTotal -= m_tourTree->topLevelItem(index)->child(i)->text(3).toDouble();
        }
        else
        {
            if( odoTotal < 0 ) odoTotal = 0;
            return odoTotal;
        }
    }
    if( odoTotal < 0 ) odoTotal = 0;
    return odoTotal;
}

double ServiceDialog::odoInUse(int row, int index)
{
    double odoTotal1 = m_tourTree->topLevelItem(index)->text(TIMETOTAL).toDouble();
    double odoTotal2 = m_tourTree->topLevelItem(index)->text(TIMETOTAL).toDouble();

    QDateTime dateTime1 = QDateTime().fromString( ui->tableWidget->item( row, DATETIME )->text(), "yyyy-MM-dd - hh:mm" );
    QString part = ui->tableWidget->item( row, PARTNAME )->text();
    int row2 = -1;

    //2nd entry availlable?
    for( int i = 0; i < row; i++ )
    {
        if( part == ui->tableWidget->item( i, PARTNAME )->text() ) row2 = i;
    }

    //Original distance
    for( int i = 0; i < m_tourTree->topLevelItem(index)->childCount(); i++ )
    {
        if( QDateTime().fromString( m_tourTree->topLevelItem(index)->child(i)->text(DATETIME), "yyyy-MM-dd - hh:mm:ss" ) > dateTime1 )
        {
            odoTotal1 -= m_tourTree->topLevelItem(index)->child(i)->text(3).toDouble();
        }
        else
        {
            break;
        }
    }

    //2nd distance
    if( row2 > -1 )
    {
        QDateTime dateTime2 = QDateTime().fromString( ui->tableWidget->item( row2, DATETIME )->text(), "yyyy-MM-dd - hh:mm" );
        for( int i = 0; i < m_tourTree->topLevelItem(index)->childCount(); i++ )
        {
            if( QDateTime().fromString( m_tourTree->topLevelItem(index)->child(i)->text(DATETIME), "yyyy-MM-dd - hh:mm:ss" ) > dateTime2 )
            {
                odoTotal2 -= m_tourTree->topLevelItem(index)->child(i)->text(3).toDouble();
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

void ServiceDialog::updateOdoInUseColumn( int index )
{
    for( int i = 0; i < ui->tableWidget->rowCount(); i++ )
    {
        ui->tableWidget->item( i, ODOINUSE )->setText( QString( "%1 km" ).arg( (int)( odoInUse( i, index ) + 0.5f ) ) );
    }
}

double ServiceDialog::secsAtDateTime(QDateTime dateTime, int index)
{
    double secsTotal = m_tourTree->topLevelItem(index)->text(4).toDouble();

    for( int i = 0; i < m_tourTree->topLevelItem(index)->childCount(); i++ )
    {
        if( QDateTime().fromString( m_tourTree->topLevelItem(index)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) > dateTime )
        {
            secsTotal -= m_tourTree->topLevelItem(index)->child(i)->text(4).toDouble();
        }
        else
        {
            return secsTotal;
        }
    }
    return secsTotal;
}

int ServiceDialog::secsInUse(int row, int index)
{
    double timeTotal1 = m_tourTree->topLevelItem(index)->text(TIMETOTAL).toDouble();
    double timeTotal2 = m_tourTree->topLevelItem(index)->text(TIMETOTAL).toDouble();

    QDateTime dateTime1 = QDateTime().fromString( ui->tableWidget->item( row, DATETIME )->text(), "yyyy-MM-dd - hh:mm" );
    QString part = ui->tableWidget->item( row, PARTNAME )->text();
    int row2 = -1;

    //2nd entry availlable?
    for( int i = 0; i < row; i++ )
    {
        if( part == ui->tableWidget->item( i, PARTNAME )->text() ) row2 = i;
    }

    //Original Time
    for( int i = 0; i < m_tourTree->topLevelItem(index)->childCount(); i++ )
    {
        if( QDateTime().fromString( m_tourTree->topLevelItem(index)->child(i)->text(DATETIME), "yyyy-MM-dd - hh:mm:ss" ) > dateTime1 )
        {
            timeTotal1 -= m_tourTree->topLevelItem(index)->child(i)->text(4).toDouble();
        }
        else
        {
            break;
        }
    }

    //2nd Time
    if( row2 > -1 )
    {
        QDateTime dateTime2 = QDateTime().fromString( ui->tableWidget->item( row2, DATETIME )->text(), "yyyy-MM-dd - hh:mm" );
        for( int i = 0; i < m_tourTree->topLevelItem(index)->childCount(); i++ )
        {
            if( QDateTime().fromString( m_tourTree->topLevelItem(index)->child(i)->text(DATETIME), "yyyy-MM-dd - hh:mm:ss" ) > dateTime2 )
            {
                timeTotal2 -= m_tourTree->topLevelItem(index)->child(i)->text(4).toDouble();
            }
            else
            {
                break;
            }
        }
    }

    //Difference
    return timeTotal2 - timeTotal1;
}

void ServiceDialog::updateSecsInUseColumn(int index)
{
    for( int i = 0; i < ui->tableWidget->rowCount(); i++ )
    {
        ui->tableWidget->item( i, TIMEINUSE )->setText( QString( "%1:%2" ).arg( (int)(secsInUse( i, index )/3600), 2, 'f', 0, '0' ).arg( QTime(0,0).addSecs( secsInUse( i, index ) ).toString( "mm:ss" ) ) );
    }
}

void ServiceDialog::updateCellColor()
{
    for( int i = 0; i < ui->tableWidget->rowCount(); i++ )
    {
        for( int j = 0; j < ui->tableWidget->columnCount(); j++ ) ui->tableWidget->item( i, j )->setBackgroundColor( QColor( 255, 0, 0, 0 ) );

        bool limitOdo = false;
        bool limitTime = false;

        if( ui->tableWidget->item( i, ODOINTER )->text().chopped( 3 ).toInt()
         <= ui->tableWidget->item( i, ODOINUSE )->text().chopped( 3 ).toInt()
         && ui->tableWidget->item( i, ODOINTER )->text().chopped( 3 ).toInt() != 0 )
        {
            limitOdo = true;
        }

        if( ui->tableWidget->item( i, TIMEINTER )->text().chopped( 2 ).toInt()
         <= ui->tableWidget->item( i, TIMEINUSE )->text().leftRef( ui->tableWidget->item( i, TIMEINUSE )->text().indexOf( ":" ) ).toInt()
         && ui->tableWidget->item( i, TIMEINTER )->text().chopped( 2 ).toInt() != 0 )
        {
            limitTime = true;
        }

        if( limitOdo || limitTime )
        {
            for( int j = 0; j < ui->tableWidget->columnCount(); j++ )
            {
                ui->tableWidget->item( i, j )->setBackgroundColor( QColor( 255, 0, 0, 64 ) );
            }
            if( limitOdo )  ui->tableWidget->item( i, ODOINTER  )->setBackgroundColor( QColor( 255, 0, 0, 128 ) );
            if( limitTime ) ui->tableWidget->item( i, TIMEINTER )->setBackgroundColor( QColor( 255, 0, 0, 128 ) );
        }
    }
}

void ServiceDialog::writeToJson( int index )
{
    QJsonObject services;
    QJsonObject info;
    for( int row = 0; row < ui->tableWidget->rowCount(); row++ )
    {
        info.insert( "dateTime",         ui->tableWidget->item( row, DATETIME )->text() );
        info.insert( "propInterval",     ui->tableWidget->item( row, ODOINTER )->text().chopped( 3 ).toInt() );
        info.insert( "propIntervalTime", ui->tableWidget->item( row, TIMEINTER )->text().chopped( 2 ).toInt() );
        info.insert( "part",             ui->tableWidget->item( row, PARTNAME )->text() );
        //info.insert( "action",           ui->tableWidget->item( row, ACTION )->text() );
        info.insert( "description",      ui->tableWidget->item( row, DESCRIPT )->text() );
        services.insert( QString::number( row ), info );
    }
    QJsonDocument doc( services );
    //write json doc into file
    QString fileName = QString( "%1/%2" ).arg( m_tourTree->topLevelItem( index )->text(1) ).arg( "service.json" );
    QFile file( fileName );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        //Try to write the JSON document
        file.write( doc.toJson() );
        file.close();
    }
}

void ServiceDialog::loadFromJson( int index )
{
    if( index < 0 ) return;

    //ui->tableWidget->clear(); //doesn't work, whyever
    int rowCnt = ui->tableWidget->rowCount();
    for( int i = 0; i < rowCnt; i++ ) ui->tableWidget->removeRow( 0 );

    //Read file
    QString fileName = QString( "%1/%2" ).arg( m_tourTree->topLevelItem( index )->text(1) ).arg( "service.json" );
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
                                                                  partList(),
                                                                  info.value( "part" ).toString(),
                                                                  info.value( "description" ).toString(),
                                                                  info.value( "action" ).toString(),
                                                                  QDateTime::fromString( info.value( "dateTime" ).toString(),
                                                                                         QString( "yyyy-MM-dd - hh:mm" ) ),
                                                                  info.value( "propInterval" ).toInt(),
                                                                  info.value( "propIntervalTime" ).toInt() );
        ui->tableWidget->insertRow( i );
        for( int j = 0; j < ui->tableWidget->columnCount(); j++ )
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setFlags( item->flags() & ~Qt::EditRole );
            ui->tableWidget->setItem( i, j, item );
        }

        fillTableRow( entryDialog, i, index );
        delete entryDialog;
    }
    updateOdoInUseColumn( index );
    updateSecsInUseColumn( index );
    updateCellColor();
}

QStringList ServiceDialog::partList()
{
    QStringList parts;
    parts.clear();
    for( int i = 0; i < ui->tableWidget->rowCount(); i++ )
    {
        if( !parts.contains( ui->tableWidget->item( i, PARTNAME )->text() ) ) parts.append( ui->tableWidget->item( i, PARTNAME )->text() );
    }
    return parts;
}

void ServiceDialog::on_comboBoxBike_currentIndexChanged(int index)
{
    loadFromJson( index );
}
