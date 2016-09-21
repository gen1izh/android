#ifndef DISHS_BY_TIME_FORM_H
#define DISHS_BY_TIME_FORM_H

#include <QWidget>

namespace Ui {
class DishsByTimeForm;
}

class DishsByTimeForm : public QWidget
{
    Q_OBJECT

public:
    explicit DishsByTimeForm(QWidget *parent = 0);
    ~DishsByTimeForm();

    void setTrapeza(const QString &trapeza);
    void setDay(const QString &day);
    void readModel(const QString &day, const QString &lunchTime);
private slots:


    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_toMainButton_clicked();

private:
    Ui::DishsByTimeForm *ui;
};

#endif // DISHS_BY_TIME_FORM_H
