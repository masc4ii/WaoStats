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

void ServiceCostPieDialog::SetData(QStringList nameList, QList<double> costList, QString currency)
{
    if( nameList.count() != costList.count() ) return;

    const QStringList colors = { "palevioletred", "darkred", "tomato", "chocolate", "sandybrown", "gold", "yellowgreen", "seagreen", "mediumturquoise", "deepskyblue" };
    QList<QColor> colorList;
    for( int i = 0; i < nameList.count(); i++ )
    {
        colorList.append( QPalette( colors[i%colors.size()] ).brush( QPalette::Window ).color() );
    }

    ui->widget->setSumUnit( currency );
    ui->widget->setSeries( nameList, costList, colorList );
}

void ServiceCostPieDialog::on_pushButtonClose_clicked()
{
    close();
}

