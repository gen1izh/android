#ifndef DISH_LIST_FORM_H
#define DISH_LIST_FORM_H

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

    void setDay(const QString &day);
    void setTrapeza(const QString &trapeza);

private slots:
   void on_dishsListView_clicked(const QModelIndex &index);

   void on_toMainButton_clicked();

private:
    Ui::DishsListForm *ui;
};

#endif // DISH_LIST_FORM_H
