#include "StatisticsDialog.h"
#include "ui_StatisticsDialog.h"

#include <qwt_legend.h>
#include <qwt_plot_layout.h>
#include <qwt_series_data.h>
#include <qwt_legend_label.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_picker_machine.h>
#include <qwt_symbol.h>
#include <qwt_plot_renderer.h>
#include <qwt_scale_draw.h>
#include <qwt_symbol.h>
#include <qwt_column_symbol.h>
#include <qwt_text.h>

#include <QList>
#include <QDebug>
#include <QObject>

class DayScaleDraw:public QwtScaleDraw
{
public:
    DayScaleDraw(void)
    {
        setTickLength( QwtScaleDiv::MinorTick, 0 );
    }
    virtual QwtText label(double v)const
    {
        if( v == 0 ) return QwtText( QObject::tr( "Monday" ) );
        else if( v == 1 ) return QwtText( QObject::tr( "Tuesday" ) );
        else if( v == 2 ) return QwtText( QObject::tr( "Wednesday" ) );
        else if( v == 3 ) return QwtText( QObject::tr( "Thursday" ) );
        else if( v == 4 ) return QwtText( QObject::tr( "Friday" ) );
        else if( v == 5 ) return QwtText( QObject::tr( "Saturday" ) );
        else if( v == 6 ) return QwtText( QObject::tr( "Sunday" ) );
        return QwtText( "" );
    }
};

class MonthScaleDraw:public QwtScaleDraw
{
public:
    MonthScaleDraw(void)
    {
        setTickLength( QwtScaleDiv::MinorTick, 0 );
    }
    virtual QwtText label(double v)const
    {
        if( v == 0 ) return QwtText( QObject::tr( "January" ) );
        else if( v == 1 ) return QwtText( QObject::tr( "February" ) );
        else if( v == 2 ) return QwtText( QObject::tr( "March" ) );
        else if( v == 3 ) return QwtText( QObject::tr( "April" ) );
        else if( v == 4 ) return QwtText( QObject::tr( "May" ) );
        else if( v == 5 ) return QwtText( QObject::tr( "June" ) );
        else if( v == 6 ) return QwtText( QObject::tr( "Juli" ) );
        else if( v == 7 ) return QwtText( QObject::tr( "August" ) );
        else if( v == 8 ) return QwtText( QObject::tr( "September" ) );
        else if( v == 9 ) return QwtText( QObject::tr( "October" ) );
        else if( v == 10 ) return QwtText( QObject::tr( "November" ) );
        else if( v == 11 ) return QwtText( QObject::tr( "December" ) );
        return QwtText( "" );
    }
};

class YearScaleDraw:public QwtScaleDraw
{
public:
    YearScaleDraw(int yearMin)
    {
        m_yearMin = yearMin;
        setTickLength( QwtScaleDiv::MinorTick, 0 );
    }
    virtual QwtText label(double v)const
    {
        return QwtText( QString::number( m_yearMin + v ) );
    }
private:
    int m_yearMin;
};

StatisticsDialog::StatisticsDialog(QWidget *parent, QTreeWidget *tree, bool filterActive) :
    QDialog(parent),
    ui(new Ui::StatisticsDialog),
    m_pTourTree( tree )
{
    ui->setupUi(this);

    ui->checkBoxFilter->setVisible( filterActive );

    //Background
    QwtPlotCanvas *canvas = (QwtPlotCanvas *)ui->qwtPlot->canvas();
    canvas->setBorderRadius( 5 );
    ui->qwtPlot->setCanvas( canvas );
    ui->qwtPlot->setCanvasBackground( Qt::white );
    ui->qwtPlot->setAxisTitle( QwtPlot::yLeft, QwtText( "Distance [km]" ) );

    // grid
    QwtPlotGrid *grid = new QwtPlotGrid;
    //grid->enableXMin( true );
    //grid->enableYMin( true );
    grid->enableX( false );
    grid->setMajorPen( Qt::lightGray, 0, Qt::DashLine );
    grid->setMinorPen( Qt::lightGray, 0 , Qt::NoPen );
    grid->attach( ui->qwtPlot );

    m_pBarChartItem = new QwtPlotMultiBarChart( "Bar Chart" );
    m_pBarChartItem->setLayoutPolicy( QwtPlotMultiBarChart::AutoAdjustSamples );
    m_pBarChartItem->setSpacing( 20 );
    m_pBarChartItem->setMargin( 3 );
    m_pBarChartItem->attach( ui->qwtPlot );

    QwtScaleDraw *scaleDraw1 = ui->qwtPlot->axisScaleDraw( QwtPlot::xBottom );
    scaleDraw1->enableComponent( QwtScaleDraw::Backbone, false );
    scaleDraw1->enableComponent( QwtScaleDraw::Ticks, false );

    QwtLegend * legend = new QwtLegend();
    ui->qwtPlot->insertLegend( legend , QwtPlot::BottomLegend );

    m_pBarChartItem->setLegendIconSize( QSize( 10, 14 ) );
    m_bikeTitles.clear();
    for( int i = 0; i < m_pTourTree->topLevelItemCount(); i++ )
    {
        if( "New" == m_pTourTree->topLevelItem( i )->text( 0 ) ) continue;
        if( "Planned" == m_pTourTree->topLevelItem( i )->text( 0 ) ) continue;
        m_bikeTitles.append( QwtText( m_pTourTree->topLevelItem( i )->text( 0 ) ) );
    }
    m_pBarChartItem->setBarTitles( m_bikeTitles );

    static const char *colors[] = { "palevioletred", "darkred", "tomato", "chocolate", "sandybrown", "gold", "yellowgreen", "seagreen", "mediumturquoise", "deepskyblue" };
    const int numBars = 10;
    for ( int i = 0; i < numBars; i++ )
    {
        QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
        symbol->setLineWidth( 2 ); // Pixel-Dimension
        symbol->setFrameStyle( QwtColumnSymbol::NoFrame );
        symbol->setPalette( QPalette( colors[i] ) );

        m_pBarChartItem->setSymbol( i, symbol );
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
    QVector< QVector<double> > samplesDays;
    for ( int day = 0; day < days; day++ )
    {
        QVector<double> values( m_bikeTitles.count() );
        int bike = 0;
        for( int j = 0; j < m_pTourTree->topLevelItemCount(); j++ )
        {
            if( "New" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;
            if( "Planned" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;

            values[bike] = 0;
            for( int i = 0; i < m_pTourTree->topLevelItem(j)->childCount(); i++ )
            {
                if( ui->checkBoxFilter->isChecked() && m_pTourTree->topLevelItem(j)->child(i)->isHidden() ) continue;

                if( QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ).date().dayOfWeek() == day+1
                 && QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) >= ui->dateEditFrom->dateTime()
                 && QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) <= ui->dateEditTo->dateTime() )
                {
                    values[bike] += m_pTourTree->topLevelItem(j)->child(i)->text(3).toDouble();
                }
            }
            bike++;
        }
        samplesDays.append(values);
    }
    ui->qwtPlot->setAxisScaleDraw( QwtPlot::xBottom, new DayScaleDraw() );
    ui->qwtPlot->setAxisTitle( QwtPlot::xBottom, QwtText( "Day of Week" ) );
    m_pBarChartItem->setSamples( samplesDays );
    ui->qwtPlot->setAxisScale( QwtPlot::xBottom, 0-0.5, 6+0.5, 1 );
}

void StatisticsDialog::plotMonths()
{
    int months = 12;
    QVector< QVector<double> > samplesMonths;
    for ( int month = 0; month < months; month++ )
    {
        QVector<double> values( m_bikeTitles.count() );
        int bike = 0;
        for( int j = 0; j < m_pTourTree->topLevelItemCount(); j++ )
        {
            if( "New" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;
            if( "Planned" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;

            values[bike] = 0;
            for( int i = 0; i < m_pTourTree->topLevelItem(j)->childCount(); i++ )
            {
                if( ui->checkBoxFilter->isChecked() && m_pTourTree->topLevelItem(j)->child(i)->isHidden() ) continue;

                if( QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ).date().month() == month+1
                 && QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) >= ui->dateEditFrom->dateTime()
                 && QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ) <= ui->dateEditTo->dateTime() )
                {
                    values[bike] += m_pTourTree->topLevelItem(j)->child(i)->text(3).toDouble();
                }
            }
            bike++;
        }
        samplesMonths.append(values);
    }
    ui->qwtPlot->setAxisScaleDraw( QwtPlot::xBottom, new MonthScaleDraw() );
    ui->qwtPlot->setAxisTitle( QwtPlot::xBottom, QwtText( "Month" ) );
    m_pBarChartItem->setSamples( samplesMonths );
    ui->qwtPlot->setAxisScale( QwtPlot::xBottom, 0-0.5, 11+0.5, 1 );
}

void StatisticsDialog::plotYears()
{
    int yearMin = 5000;
    int yearMax = 0;
    QVector< QVector<double> > years;
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

    QVector< QVector<double> > samplesYears;
    for ( int year = yearMin; year <= yearMax; year++ )
    {
        QVector<double> values( m_bikeTitles.count() );
        int bike = 0;
        for( int j = 0; j < m_pTourTree->topLevelItemCount(); j++ )
        {
            if( "New" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;
            if( "Planned" == m_pTourTree->topLevelItem( j )->text( 0 ) ) continue;

            values[bike] = 0;
            for( int i = 0; i < m_pTourTree->topLevelItem(j)->childCount(); i++ )
            {
                if( ui->checkBoxFilter->isChecked() && m_pTourTree->topLevelItem(j)->child(i)->isHidden() ) continue;

                if( QDateTime().fromString( m_pTourTree->topLevelItem(j)->child(i)->text(0), "yyyy-MM-dd - hh:mm:ss" ).date().year() == year )
                {
                    values[bike] += m_pTourTree->topLevelItem(j)->child(i)->text(3).toDouble();
                }
            }
            bike++;
        }
        samplesYears.append(values);
    }
    ui->qwtPlot->setAxisScaleDraw( QwtPlot::xBottom, new YearScaleDraw( yearMin ) );
    ui->qwtPlot->setAxisTitle( QwtPlot::xBottom, QwtText( "Year" ) );
    m_pBarChartItem->setSamples( samplesYears );
    ui->qwtPlot->setAxisScale( QwtPlot::xBottom, 0-0.5, yearMax-yearMin+0.5, 1 );
}

void StatisticsDialog::on_comboBoxStyle_currentIndexChanged(int index)
{
    if( index ) m_pBarChartItem->setStyle( QwtPlotMultiBarChart::Stacked );
    else m_pBarChartItem->setStyle( QwtPlotMultiBarChart::Grouped );
    ui->qwtPlot->replot();
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

    ui->qwtPlot->replot();
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

