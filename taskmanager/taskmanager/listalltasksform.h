#ifndef LISTALLTASKSFORM_H
#define LISTALLTASKSFORM_H

#include <QWidget>

namespace Ui {
class ListAllTasksForm;
}

class ListAllTasksForm : public QWidget
{
  Q_OBJECT

public:
  explicit ListAllTasksForm(QWidget *parent = 0);
  ~ListAllTasksForm();

private:
  Ui::ListAllTasksForm *ui;
};

#endif // LISTALLTASKSFORM_H
