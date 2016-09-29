#ifndef TASKMANAGERFORM_H
#define TASKMANAGERFORM_H

#include <QWidget>

namespace Ui {
class TaskManagerForm;
}

class TaskManagerForm : public QWidget
{
  Q_OBJECT

public:
  explicit TaskManagerForm(QWidget *parent = 0);
  ~TaskManagerForm();

private:
  Ui::TaskManagerForm *ui;
};

#endif // TASKMANAGERFORM_H
