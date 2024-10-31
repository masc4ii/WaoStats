#include "ServiceCostPieDialog.h"
#include "ui_ServiceCostPieDialog.h"

ServiceCostPieDialog::ServiceCostPieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServiceCostPieDialog)
{
    ui->setupUi(this);

    ui->widget->setTagFont(this->font());
    ui->widget->setLegendFont(this->font());
    QFont sumFont = this->font();
    sumFont.setPointSizeF(sumFont.pointSizeF() * 2);
    ui->widget->setSumFont(sumFont);
    ui->widget->setTitle("Title");
}

ServiceCostPieDialog::~ServiceCostPieDialog()
{
    delete ui;
}

QStringList extendColors()
{
    const QStringList colors = { "palevioletred", "darkred", "tomato", "chocolate", "sandybrown", "gold", "yellowgreen", "seagreen", "mediumturquoise", "deepskyblue" };
    QStringList extendedColors = colors;

    // Helle Farben hinzufügen
    for (const auto& colorName : colors) {
        QColor color(colorName);
        color = color.lighter(150);  // 150% Helligkeit
        extendedColors.append(color.name());
    }

    // Dunkle Farben hinzufügen
    for (const auto& colorName : colors) {
        QColor color(colorName);
        color = color.darker(150);  // 150% Dunkelheit
        extendedColors.append(color.name());
    }

    return extendedColors;
}

void ServiceCostPieDialog::SetData(QStringList nameList, QList<double> costList, QString currency)
{
    if( nameList.count() != costList.count() ) return;

    QStringList extendedColors = extendColors();
    QList<QColor> colorList;
    for( int i = 0; i < nameList.count(); i++ )
    {
        colorList.append( QPalette( extendedColors[i%extendedColors.size()] ).brush( QPalette::Window ).color() );
    }

    ui->widget->setSumUnit( currency );
    ui->widget->setSeries( nameList, costList, colorList );
}

void ServiceCostPieDialog::on_pushButtonClose_clicked()
{
    close();
}

