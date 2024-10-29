#ifndef SERVICECOSTPIEDIALOG_H
#define SERVICECOSTPIEDIALOG_H

#include <QDialog>

namespace Ui {
class ServiceCostPieDialog;
}

class ServiceCostPieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServiceCostPieDialog(QWidget *parent = nullptr);
    ~ServiceCostPieDialog();

    void SetData( QStringList nameList, QList<double> costList, QString currency );

private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::ServiceCostPieDialog *ui;
};

#endif // SERVICECOSTPIEDIALOG_H
