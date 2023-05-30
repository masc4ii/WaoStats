#ifndef ADBSELECTDEVICEDIALOG_H
#define ADBSELECTDEVICEDIALOG_H

#include <QDialog>

namespace Ui {
class AdbSelectDeviceDialog;
}

class AdbSelectDeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdbSelectDeviceDialog(QWidget *parent = nullptr);
    ~AdbSelectDeviceDialog();
    QString selectedDeviceId( void );

private slots:
    void on_pushButtonRefresh_clicked();

private:
    Ui::AdbSelectDeviceDialog *ui;
    void scan( void );
    void reset( void );
};

#endif // ADBSELECTDEVICEDIALOG_H
