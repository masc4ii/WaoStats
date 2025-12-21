#pragma once

#include <QDialog>

namespace qmapcontrol {
    class LayerHillshading;
}

namespace Ui {
class HillShadingSettingsDialog;
}

class HillShadingSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HillShadingSettingsDialog(std::shared_ptr<qmapcontrol::LayerHillshading> layerHillShading, QWidget *parent = nullptr);
    ~HillShadingSettingsDialog();

private slots:
    void on_horizontalSliderOpacity_valueChanged(int value);
    void on_horizontalSliderDirection_valueChanged(int value);
    void on_horizontalSliderHeight_valueChanged(int value);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::HillShadingSettingsDialog *ui;
    std::shared_ptr<qmapcontrol::LayerHillshading> m_layerHillShading;
    int m_direction;
    int m_height;
    int m_opacity;
};

