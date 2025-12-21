#include "HillShadingSettingsDialog.h"
#include "ui_HillShadingSettingsDialog.h"

#include <QMapControl/LayerHillshading.h>

HillShadingSettingsDialog::HillShadingSettingsDialog(std::shared_ptr<qmapcontrol::LayerHillshading> layerHillShading, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HillShadingSettingsDialog),
    m_layerHillShading(layerHillShading)
{
    ui->setupUi(this);
    ui->horizontalSliderDirection->setValue(m_layerHillShading->lightDirection());
    ui->horizontalSliderHeight->setValue(m_layerHillShading->lightHeight());
    ui->horizontalSliderOpacity->setValue(m_layerHillShading->opacity());
    m_direction = m_layerHillShading->lightDirection();
    m_height = m_layerHillShading->lightHeight();
    m_opacity = m_layerHillShading->opacity();
}

HillShadingSettingsDialog::~HillShadingSettingsDialog()
{
    delete ui;
}

void HillShadingSettingsDialog::on_horizontalSliderOpacity_valueChanged(int value)
{
    m_layerHillShading->setOpacity(value);
    ui->labelOpacity->setText(QString("%1 \%").arg(value));
}

void HillShadingSettingsDialog::on_horizontalSliderDirection_valueChanged(int value)
{
    m_layerHillShading->setLightDirection(value);
    ui->labelDirection->setText(QString("%1 °").arg(value));
}

void HillShadingSettingsDialog::on_horizontalSliderHeight_valueChanged(int value)
{
    m_layerHillShading->setLightHeight(value);
    ui->labelHeight->setText(QString::number(value));
}

void HillShadingSettingsDialog::on_buttonBox_accepted()
{
    accept();
}

void HillShadingSettingsDialog::on_buttonBox_rejected()
{
    m_layerHillShading->setOpacity(m_opacity);
    m_layerHillShading->setLightDirection(m_direction);
    m_layerHillShading->setLightHeight(m_height);
    reject();
}
