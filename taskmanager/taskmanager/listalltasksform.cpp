#include "listalltasksform.h"
#include "ui_listalltasksform.h"

ListAllTasksForm::ListAllTasksForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ListAllTasksForm)
{
  ui->setupUi(this);
}

ListAllTasksForm::~ListAllTasksForm()
{
  delete ui;
}
