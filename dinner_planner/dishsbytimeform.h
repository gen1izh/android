#ifndef DISHS_BY_TIME_FORM_H
#define DISHS_BY_TIME_FORM_H

#include <QShowEvent>
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

  void readModel(const QString &day, const QString &lunchTime);
  void setCurrentDay(const QString &day);
private slots:


    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_toMainButton_clicked();

    void on_backButton_clicked();

private:
    Ui::DishsByTimeForm *ui;

protected:
    void showEvent(QShowEvent *event);
};

#endif // DISHS_BY_TIME_FORM_H
