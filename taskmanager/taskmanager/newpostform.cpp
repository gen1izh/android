#include "newpostform.h"
#include "ui_newpostform.h"

NewPostForm::NewPostForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::NewPostForm)
{
  ui->setupUi(this);
}

NewPostForm::~NewPostForm()
{
  delete ui;
}
