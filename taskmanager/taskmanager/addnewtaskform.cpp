#include "addnewtaskform.h"
#include "ui_addnewtaskform.h"

AddNewTaskForm::AddNewTaskForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::AddNewTaskForm)
{
  ui->setupUi(this);
}

AddNewTaskForm::~AddNewTaskForm()
{
  delete ui;
}
