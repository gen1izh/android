#include "addnewtaskform.h"
#include "ui_addnewtaskform.h"

#include "commonsharedsingleton.h"

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

void AddNewTaskForm::on_chooseDateButton_clicked()
{
    ui->toolBox->setCurrentIndex(1);
}

void AddNewTaskForm::on_calendarWidget_clicked(const QDate &date)
{
    ui->toolBox->setCurrentIndex(0);
    ui->dateLabel->setText(date.toString("dd.MM.yyyy"));
}

void AddNewTaskForm::on_saveButton_clicked()
{
    CommonSharedSingleton::instance().getTaskModel()->showAllPointsNames();
}
