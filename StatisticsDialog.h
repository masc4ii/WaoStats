#ifndef STATISTICSDIALOG_H
#define STATISTICSDIALOG_H

#include <QDialog>
#include <QTreeWidget>

namespace Ui {
class StatisticsDialog;
}

class StatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsDialog(QWidget *parent = nullptr, QTreeWidget *tree = nullptr, bool filterActive = false);
    ~StatisticsDialog();

private slots:
    void on_comboBoxStyle_currentIndexChanged(int index);
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_dateEditFrom_dateTimeChanged(const QDateTime &dateTime);
    void on_dateEditTo_dateTimeChanged(const QDateTime &dateTime);
    void on_checkBoxFilter_toggled(bool checked);

    void on_comboBoxType_currentIndexChanged(int index);

private:
    enum Type{
        Distance = 0,
        Ascent,
        TimeMotion
    };

    Ui::StatisticsDialog *ui;
    QTreeWidget *m_pTourTree;
    QStringList m_bikeTitles;
    const QStringList m_colors = { "palevioletred", "darkred", "tomato", "chocolate", "sandybrown", "gold", "yellowgreen", "seagreen", "mediumturquoise", "deepskyblue" };

    void plotCreate( void );
    void plotDaysOfWeek( void );
    void plotMonths( void );
    void plotYears( void );
};

#endif // STATISTICSDIALOG_H
