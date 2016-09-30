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

private slots:
    void on_openButton_clicked();

    void on_chooseDateCalendarWidget_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_deleteButton_clicked();

private:
  Ui::ListAllTasksForm *ui;
};

#endif // LISTALLTASKSFORM_H
