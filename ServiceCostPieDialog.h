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

    void SetData(QStringList nameList, QList<double> costListM, QList<int> costListT, QString currency );

private slots:
    void on_pushButtonClose_clicked();
    void on_pushButtonMoney_clicked();
    void on_pushButtonTime_clicked();

private:
    void drawCostM( void );
    void drawCostT( void );

    Ui::ServiceCostPieDialog *ui;
    QStringList m_nameList;
    QList<int> m_costListT;
    QList<double> m_costListM;
    QString m_currency;
};

#endif // SERVICECOSTPIEDIALOG_H
