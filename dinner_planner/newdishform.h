#ifndef NEW_DISH_FORM_H
#define NEW_DISH_FORM_H

#include <QWidget>

namespace Ui {
class NewDishForm;
}

class NewDishForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewDishForm(QWidget *parent = 0);
    ~NewDishForm();

    void clearEdits();

private slots:
    void on_saveButton_clicked();

    void on_toMainButton_clicked();

private:
    Ui::NewDishForm *ui;
};

#endif // NEW_DISH_FORM_H
