#ifndef DISH_LIST_FORM_H
#define DISH_LIST_FORM_H

#include <QShowEvent>
#include <QWidget>

namespace Ui {
class DishsListForm;
}

class DishsListForm : public QWidget
{
    Q_OBJECT

public:
    explicit DishsListForm(QWidget *parent = 0);
    ~DishsListForm();

  void setCurrentDay(const QString &day);
private slots:
   void on_dishsListView_clicked(const QModelIndex &index);

   void on_toMainButton_clicked();

   void on_backButton_clicked();

private:
    Ui::DishsListForm *ui;

protected:
    void showEvent(QShowEvent *event);
};

#endif // DISH_LIST_FORM_H
