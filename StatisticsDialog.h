#ifndef STATISTICSDIALOG_H
#define STATISTICSDIALOG_H

#include <QDialog>
#include <QTreeWidget>

#include <qwt_plot_multi_barchart.h>

namespace Ui {
class StatisticsDialog;
}

class StatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsDialog(QWidget *parent = nullptr, QTreeWidget *tree = nullptr);
    ~StatisticsDialog();

private slots:
    void on_comboBoxStyle_currentIndexChanged(int index);
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_dateEditFrom_dateTimeChanged(const QDateTime &dateTime);
    void on_dateEditTo_dateTimeChanged(const QDateTime &dateTime);

private:
    Ui::StatisticsDialog *ui;
    QTreeWidget *m_tourTree;
    QwtPlotMultiBarChart *m_pBarChartItem;
    QList<QwtText> m_bikeTitles;

    void plotCreate( void );
    void plotDaysOfWeek( void );
    void plotMonths( void );
    void plotYears( void );
};

#endif // STATISTICSDIALOG_H
