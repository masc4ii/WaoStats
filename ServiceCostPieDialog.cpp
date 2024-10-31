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

    //White background
    ui->widget->setAutoFillBackground(true);
    QPalette palette = ui->widget->palette();
    palette.setColor(QPalette::Window, Qt::white);
    ui->widget->setPalette(palette);
}

void ServiceCostPieDialog::on_pushButtonClose_clicked()
{
    close();
}

