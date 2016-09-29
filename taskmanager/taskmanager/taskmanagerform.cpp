#include "taskmanagerform.h"
#include "ui_taskmanagerform.h"

TaskManagerForm::TaskManagerForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TaskManagerForm)
{
  ui->setupUi(this);
}

TaskManagerForm::~TaskManagerForm()
{
  delete ui;
}
