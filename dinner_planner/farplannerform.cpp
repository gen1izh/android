#include "farplannerform.h"
#include "ui_farplannerform.h"
#include "models.h"

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

void FarPlannerForm::on_chooseDateButton_clicked()
{
    QDate date = ui->calendarWidget->selectedDate();
    GlobalVariables::Instance().setCurrentDay(date.toString("dd.MM.yyyy"));
    GlobalVariables::Instance().resetCurrentDayOnLabels();
    hide();
}
