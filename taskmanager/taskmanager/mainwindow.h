#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
    void on_postAction_triggered();

    void on_settingsAction_triggered();

    void on_purposeAction_triggered();

    void on_tasksListAction_triggered();

    void on_addTaskAction_triggered();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
