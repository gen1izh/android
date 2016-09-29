#include "newpurposeform.h"
#include "ui_newpurposeform.h"

NewPurposeForm::NewPurposeForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::NewPurposeForm)
{
  ui->setupUi(this);
}

NewPurposeForm::~NewPurposeForm()
{
  delete ui;
}
