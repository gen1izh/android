#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "commonsharedsingleton.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_postAction_triggered()
{
    CommonSharedSingleton::instance().newPostForm->show();
}

void MainWindow::on_settingsAction_triggered()
{
    CommonSharedSingleton::instance().settingsForm->show();
}

void MainWindow::on_purposeAction_triggered()
{
    CommonSharedSingleton::instance().newPurposeForm->show();
}

void MainWindow::on_tasksListAction_triggered()
{
    CommonSharedSingleton::instance().listAllTasksForm->show();
}

void MainWindow::on_addTaskAction_triggered()
{
    CommonSharedSingleton::instance().addNewTaskForm->show();
}
