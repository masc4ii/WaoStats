#ifndef SERVICEDIALOG_H
#define SERVICEDIALOG_H

#include <QDialog>
#include <QTreeWidget>

#include "ServiceEntryDialog.h"

namespace Ui {
class ServiceDialog;
}

class ServiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServiceDialog(QWidget *parent = nullptr, QTreeWidget *tree = nullptr);
    ~ServiceDialog();
    bool bikeNeedsService( int index );

private slots:
    void on_pushButtonClose_clicked();
    void on_pushButtonAdd_clicked();
    void on_pushButtonDelete_clicked();
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_comboBoxBike_currentIndexChanged(int index);

private:
    Ui::ServiceDialog *ui;

    void fillTableRow(ServiceEntryDialog *entryDialog, int row , int index);
    double odoAtDateTime(QDateTime dateTime , int index);
    double odoInUse( int row, int index );
    void updateOdoInUseColumn( int index );
    void updateCellColor( void );
    void writeToJson( int index );
    void loadFromJson( int index );
    QStringList partList( void );

    QTreeWidget *m_tourTree;
};

#endif // SERVICEDIALOG_H
