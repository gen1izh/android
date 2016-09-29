#include "createreportform.h"
#include "ui_createreportform.h"

CreateReportForm::CreateReportForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::CreateReportForm)
{
  ui->setupUi(this);
}

CreateReportForm::~CreateReportForm()
{
  delete ui;
}
