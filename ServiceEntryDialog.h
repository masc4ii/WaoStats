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
                                QString part = "Chain",
                                QString description = "brand xy",
                                QString actionText = "Replaced",
                                QDateTime dateTime = QDateTime::currentDateTime() );
    ~ServiceEntryDialog();
    QString part( void );
    QString description( void );
    QString actionText( void );
    QDateTime dateTime( void );

private slots:
    void on_pushButtonNow_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::ServiceEntryDialog *ui;
};

#endif // SERVICEENTRYDIALOG_H
