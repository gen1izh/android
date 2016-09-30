#include "listalltasksform.h"
#include "ui_listalltasksform.h"

#include "commonsharedsingleton.h"

#include <QDate>

ListAllTasksForm::ListAllTasksForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ListAllTasksForm)
{
  ui->setupUi(this);

  ui->dateLabel->setText(QDate::currentDate().toString("dd.MM.yyyy"));
}

ListAllTasksForm::~ListAllTasksForm()
{
  delete ui;
}

void ListAllTasksForm::on_openButton_clicked()
{
    bool ok;
    // В списке задач должно быть так 1:помыть пол 2:вытереть подоконник и тд, то есть цифра это id.
    int id =  QString(QString(ui->tasksList->currentIndex().data(Qt::DisplayRole).toString()).split(":").at(0)).toInt(&ok, 10);
    CommonSharedSingleton::instance().setCurrentTaskId(id);
    CommonSharedSingleton::instance().taskManagerForm->show();
}

void ListAllTasksForm::on_chooseDateCalendarWidget_clicked()
{
    ui->toolBox->setCurrentIndex(1);
}

void ListAllTasksForm::on_calendarWidget_clicked(const QDate &date)
{
    ui->toolBox->setCurrentIndex(0);
    ui->dateLabel->setText(date.toString("dd.MM.yyyy"));
}

void ListAllTasksForm::on_deleteButton_clicked()
{
    bool ok;
    // В списке задач должно быть так 1:помыть пол 2:вытереть подоконник и тд, то есть цифра это id.
    int id =  QString(QString(ui->tasksList->currentIndex().data(Qt::DisplayRole).toString()).split(":").at(0)).toInt(&ok, 10);


}
