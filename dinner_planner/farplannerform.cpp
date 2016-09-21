#include "farplannerform.h"
#include "ui_farplannerform.h"

FarPlannerForm::FarPlannerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FarPlannerForm)
{
    ui->setupUi(this);
}

FarPlannerForm::~FarPlannerForm()
{
    delete ui;
}
