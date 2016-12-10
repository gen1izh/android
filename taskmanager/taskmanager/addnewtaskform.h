#ifndef ADDNEWTASKFORM_H
#define ADDNEWTASKFORM_H

#include <QWidget>

namespace Ui {
class AddNewTaskForm;
}

class AddNewTaskForm : public QWidget
{
  Q_OBJECT

public:
  explicit AddNewTaskForm(QWidget *parent = 0);
  ~AddNewTaskForm();

private slots:
    void on_chooseDateButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_saveButton_clicked();

private:
  Ui::AddNewTaskForm *ui;
};

#endif // ADDNEWTASKFORM_H
