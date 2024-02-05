#include "StatisticsDialog.h"
#include "ui_StatisticsDialog.h"

#include <QList>
#include <QDebug>
#include <QObject>

StatisticsDialog::StatisticsDialog(QWidget *parent, QTreeWidget *tree, bool filterActive) :
    QDialog(parent),
    ui(new Ui::StatisticsDialog),
    m_pTourTree( tree )
{
    ui->setupUi(this);

    ui->checkBoxFilter->setVisible( filterActive );

    m_bikeTitles.clear();
    for( int i = 0; i < m_pTourTree->topLevelItemCount(); i++ )
    {
        if( "New" == m_pTourTree->topLevelItem( i )->text( 0 ) ) continue;
        if( "Planned" == m_pTourTree->topLevelItem( i )->text( 0 ) ) continue;
        m_bikeTitles.append( m_pTourTree->topLevelItem( i )->text( 0 ) );
    }

    ui->dateEditTo->setDateTime( QDateTime::currentDateTime() );
    plotDaysOfWeek();
}

StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

void StatisticsDialog::plotDaysOfWeek()
{
    int days = 7;
    ui->widgetPlot->clearItems();
    ui->widgetPlot->clearPlottables();
    QVector<double> vectorDays = QVector<double>() << 0 << 1 << 2 << 3 << 4 << 5 << 6;
    int bike = 0;
    QVector<QCPBars*> bikeBars;
    for( int j = 0; j < m_pTourTree->topLevelItemCount(); j++ )
    {
        if( "New" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;
        if( "Planned" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;

        QVector<double> vectorBike;

        for ( int day = 0; day < days; day++ )
        {
            double value = 0;
            for( int i = 0; i < m_pTourTree->topLevelItem(j)->childCount(); i++ )
            {
                if( ui->checkBoxFilter->isChecked() && m_pTourTree->topLevelItem(j)->child(i)->isHidden() ) continue;

                if( QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ).date().dayOfWeek() == day+1
                    && QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) >= ui->dateEditFrom->dateTime()
                    && QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) <= ui->dateEditTo->dateTime() )
                {
                    value += m_pTourTree->topLevelItem(j)->child(i)->text(3).toDouble();
                }
            }
            vectorBike.append( value );
        }

        QCPBars *bikeBar = new QCPBars(ui->widgetPlot->xAxis, ui->widgetPlot->yAxis);
        QPen pen = QPen( QPalette( m_colors[bike] ).brush( QPalette::Window ).color() );
        pen.setWidth(0);
        bikeBar->setPen( pen );
        bikeBar->setBrush( QBrush( QPalette( m_colors[bike] ).brush( QPalette::Window ) ) );
        bikeBar->setData(vectorDays,vectorBike);
        bike++;
        bikeBars.append(bikeBar);
    }

    if( ui->comboBoxStyle->currentIndex() ) ui->widgetPlot->stackBars( bikeBars );
    else ui->widgetPlot->groupBars( bikeBars );

    ui->widgetPlot->setLegendTitles( bikeBars, m_bikeTitles );
    ui->widgetPlot->setDayTicker();
    ui->widgetPlot->yAxis->rescale();
    ui->widgetPlot->yAxis->setRangeUpper( ui->widgetPlot->yAxis->range().upper * 1.05 );
    ui->widgetPlot->replot();
}

void StatisticsDialog::plotMonths()
{
    int months = 12;
    ui->widgetPlot->clearItems();
    ui->widgetPlot->clearPlottables();
    QVector<double> vectorMonths = QVector<double>() << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11;
    int bike = 0;
    QVector<QCPBars*> bikeBars;
    for( int j = 0; j < m_pTourTree->topLevelItemCount(); j++ )
    {
        if( "New" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;
        if( "Planned" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;

        QVector<double> vectorBike;

        for ( int month = 0; month < months; month++ )
        {
            double value = 0;
            for( int i = 0; i < m_pTourTree->topLevelItem(j)->childCount(); i++ )
            {
                if( ui->checkBoxFilter->isChecked() && m_pTourTree->topLevelItem(j)->child(i)->isHidden() ) continue;

                if( QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ).date().month() == month+1
                    && QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) >= ui->dateEditFrom->dateTime()
                    && QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) <= ui->dateEditTo->dateTime() )
                {
                    value += m_pTourTree->topLevelItem(j)->child(i)->text(3).toDouble();
                }
            }
            vectorBike.append( value );
        }

        QCPBars *bikeBar = new QCPBars(ui->widgetPlot->xAxis, ui->widgetPlot->yAxis);
        QPen pen = QPen( QPalette( m_colors[bike] ).brush( QPalette::Window ).color() );
        pen.setWidth(0);
        bikeBar->setPen( pen );
        bikeBar->setBrush( QBrush( QPalette( m_colors[bike] ).brush( QPalette::Window ) ) );
        bikeBar->setData( vectorMonths, vectorBike );
        bike++;
        bikeBars.append(bikeBar);
    }

    if( ui->comboBoxStyle->currentIndex() ) ui->widgetPlot->stackBars( bikeBars );
    else ui->widgetPlot->groupBars( bikeBars );

    ui->widgetPlot->setLegendTitles( bikeBars, m_bikeTitles );
    ui->widgetPlot->setMonthTicker();
    ui->widgetPlot->yAxis->rescale();
    ui->widgetPlot->yAxis->setRangeUpper( ui->widgetPlot->yAxis->range().upper * 1.05 );
    ui->widgetPlot->replot();
}

void StatisticsDialog::plotYears()
{
    int yearMin = 5000;
    int yearMax = 0;
    for( int j = 0; j < m_pTourTree->topLevelItemCount(); j++ )
    {
        if( "New" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;
        if( "Planned" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;

        for( int i = 0; i < m_pTourTree->topLevelItem(j)->childCount(); i++ )
        {
            if( ui->checkBoxFilter->isChecked() && m_pTourTree->topLevelItem(j)->child(i)->isHidden() ) continue;

            int year = QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ).date().year();
            if( year > yearMax )
            {
                yearMax = year;
            }
            if( year < yearMin )
            {
                yearMin = year;
            }
        }
    }

    ui->widgetPlot->clearItems();
    ui->widgetPlot->clearPlottables();
    QVector<double> vectorYears;
    for ( int year = yearMin; year <= yearMax; year++ ) vectorYears << year;
    int bike = 0;
    QVector<QCPBars*> bikeBars;
    for( int j = 0; j < m_pTourTree->topLevelItemCount(); j++ )
    {
        if( "New" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;
        if( "Planned" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;

        QVector<double> vectorBike;

        for ( int year = yearMin; year <= yearMax; year++ )
        {
            double value = 0;
            for( int i = 0; i < m_pTourTree->topLevelItem(j)->childCount(); i++ )
            {
                if( ui->checkBoxFilter->isChecked() && m_pTourTree->topLevelItem(j)->child(i)->isHidden() ) continue;

                if( QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ).date().year() == year )
                {
                    value += m_pTourTree->topLevelItem(j)->child(i)->text(3).toDouble();
                }
            }
            vectorBike.append( value );
        }

        QCPBars *bikeBar = new QCPBars(ui->widgetPlot->xAxis, ui->widgetPlot->yAxis);
        QPen pen = QPen( QPalette( m_colors[bike] ).brush( QPalette::Window ).color() );
        pen.setWidth(0);
        bikeBar->setPen( pen );
        bikeBar->setBrush( QBrush( QPalette( m_colors[bike] ).brush( QPalette::Window ) ) );
        bikeBar->setData(vectorYears,vectorBike);
        bike++;
        bikeBars.append(bikeBar);
    }

    if( ui->comboBoxStyle->currentIndex() ) ui->widgetPlot->stackBars( bikeBars );
    else ui->widgetPlot->groupBars( bikeBars );

    ui->widgetPlot->setLegendTitles( bikeBars, m_bikeTitles );
    ui->widgetPlot->setYearTicker();
    ui->widgetPlot->xAxis->setRange( yearMin - 0.5, yearMax + 0.5 );
    ui->widgetPlot->yAxis->rescale();
    ui->widgetPlot->yAxis->setRangeUpper( ui->widgetPlot->yAxis->range().upper * 1.05 );
    ui->widgetPlot->replot();
}

void StatisticsDialog::on_comboBoxStyle_currentIndexChanged(int index)
{
    Q_UNUSED( index );
    plotCreate();
}

void StatisticsDialog::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->dateEditFrom->setEnabled( arg1 != "Years" );
    ui->dateEditTo->setEnabled( arg1 != "Years" );
    plotCreate();
}

void StatisticsDialog::plotCreate()
{
    if( ui->comboBox->currentText() == "Days of Week" ) plotDaysOfWeek();
    else if( ui->comboBox->currentText() == "Months" ) plotMonths();
    else if( ui->comboBox->currentText() == "Years" ) plotYears();
}

void StatisticsDialog::on_dateEditFrom_dateTimeChanged(const QDateTime &dateTime)
{
    Q_UNUSED( dateTime );
    plotCreate();
}

void StatisticsDialog::on_dateEditTo_dateTimeChanged(const QDateTime &dateTime)
{
    Q_UNUSED( dateTime );
    plotCreate();
}

void StatisticsDialog::on_checkBoxFilter_toggled(bool checked)
{
    Q_UNUSED( checked );
    plotCreate();
}

