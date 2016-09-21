#ifndef LUNCH_TIMES_LIST_H
#define LUNCH_TIMES_LIST_H

#include <QWidget>

namespace Ui {
class LunchTimesList;
}

class LunchTimesList : public QWidget
{
    Q_OBJECT

public:
    explicit LunchTimesList(QWidget *parent = 0);
    ~LunchTimesList();

    void setDay(const QString &day);

private slots:

    void on_lunchTimesListWidget_clicked(const QModelIndex &index);

    void on_toMainButton_clicked();

    void on_calendarButton_clicked();

private:
    Ui::LunchTimesList *ui;
};

#endif // LUNCH_TIMES_LIST_H
