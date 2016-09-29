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

private:
  Ui::AddNewTaskForm *ui;
};

#endif // ADDNEWTASKFORM_H
