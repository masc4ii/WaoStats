#include "ServiceCostPieDialog.h"
#include "ui_ServiceCostPieDialog.h"

ServiceCostPieDialog::ServiceCostPieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServiceCostPieDialog)
{
    ui->setupUi(this);

    setWindowFlags( Qt::Dialog | Qt::WindowTitleHint | Qt::WindowCloseButtonHint );

    ui->widget->setTagFont(this->font());
    ui->widget->setLegendFont(this->font());
    QFont sumFont = this->font();
    sumFont.setPointSizeF(sumFont.pointSizeF() * 2);
    ui->widget->setSumFont(sumFont);
    ui->widget->setTitle("Title");

    //White background
    ui->widget->setAutoFillBackground(true);
    QPalette palette = ui->widget->palette();
    palette.setColor(QPalette::Window, Qt::white);
    ui->widget->setPalette(palette);
}

ServiceCostPieDialog::~ServiceCostPieDialog()
{
    delete ui;
}

QStringList extendColors()
{
    const QStringList colors = { "palevioletred", "darkred", "tomato", "chocolate", "sandybrown", "gold", "yellowgreen", "seagreen", "mediumturquoise", "deepskyblue" };
    QStringList extendedColors = colors;

    // add bright colors
    for (const auto& colorName : colors) {
        QColor color(colorName);
        color = color.lighter(130);  // 130% brighter
        extendedColors.append(color.name());
    }

    // add dark colors
    for (const auto& colorName : colors) {
        QColor color(colorName);
        color = color.darker(150);  // 150% darker
        extendedColors.append(color.name());
    }

    return extendedColors;
}

void ServiceCostPieDialog::SetData(QStringList nameList, QList<double> costListM, QList<int> costListT, QString currency)
{
    //Error? Nothing to do...
    if( nameList.count() != costListM.count() ) return;
    if( nameList.count() != costListT.count() ) return;

    m_nameList = nameList;
    m_costListM = costListM;
    m_costListT = costListT;
    m_currency = currency;

    drawCostM();
}

void ServiceCostPieDialog::on_pushButtonClose_clicked()
{
    close();
}

void ServiceCostPieDialog::drawCostM()
{
    QStringList nameList = m_nameList;
    QList<double> costListM = m_costListM;

    //Filter empty entries
    for( int i = nameList.count() - 1; i >= 0; i-- )
    {
        if( costListM.at(i) == 0.0 )
        {
            nameList.removeAt(i);
            costListM.removeAt(i);
        }
    }

    //Colors
    QStringList extendedColors = extendColors();
    QList<QColor> colorList;
    for( int i = 0; i < nameList.count(); i++ )
    {
        colorList.append( QPalette( extendedColors[i%extendedColors.size()] ).brush( QPalette::Window ).color() );
    }

    //Setup
    ui->widget->setSumUnit( m_currency );
    ui->widget->setSeries( nameList, costListM, colorList );

    //White background
    ui->widget->setAutoFillBackground(true);
    QPalette palette = ui->widget->palette();
    palette.setColor(QPalette::Window, Qt::white);
    ui->widget->setPalette(palette);
    ui->widget->repaint();
}

void ServiceCostPieDialog::drawCostT()
{
    QStringList nameList = m_nameList;
    QList<double> costListT;

    //Filter empty entries
    for( int i = nameList.count() - 1; i >= 0; i-- )
    {
        if( m_costListT.at(i) == 0 )
        {
            nameList.removeAt(i);
        }
        else
        {
            costListT.prepend(m_costListT.at(i));
        }
    }

    //Colors
    QStringList extendedColors = extendColors();
    QList<QColor> colorList;
    for( int i = 0; i < nameList.count(); i++ )
    {
        colorList.append( QPalette( extendedColors[i%extendedColors.size()] ).brush( QPalette::Window ).color() );
    }

    //Setup
    ui->widget->setSumUnit( "hh:mm" );
    ui->widget->setSeries( nameList, costListT, colorList );
    ui->widget->repaint();
}

void ServiceCostPieDialog::on_pushButtonMoney_clicked()
{
    blockSignals( true );
    ui->pushButtonTime->setChecked( false );
    blockSignals( false );
    drawCostM();
}

void ServiceCostPieDialog::on_pushButtonTime_clicked()
{
    blockSignals( true );
    ui->pushButtonMoney->setChecked( false );
    blockSignals( false );
    drawCostT();
}

