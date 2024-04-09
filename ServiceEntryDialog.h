#ifndef SERVICEENTRYDIALOG_H
#define SERVICEENTRYDIALOG_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class ServiceEntryDialog;
}

class ServiceEntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServiceEntryDialog(QWidget *parent = nullptr,
                                QStringList partList = QStringList(),
                                QString part = "",
                                QString description = "",
                                QString actionText = "",
                                QDateTime dateTime = QDateTime::currentDateTime(),
                                int intervalDistance = 0,
                                int intervalTime = 0,
                                QTime costsT = QTime(0, 0),
                                double costsM = 0.0);
    ~ServiceEntryDialog();
    QString part( void );
    QString description( void );
    QString actionText( void );
    QDateTime dateTime( void );
    int intervalDistance( void );
    int intervalHours( void );
    double costsM( void );
    QTime costsT( void );

private slots:
    void on_pushButtonNow_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::ServiceEntryDialog *ui;
};

#endif // SERVICEENTRYDIALOG_H
