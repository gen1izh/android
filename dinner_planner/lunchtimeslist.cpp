#include "lunchtimeslist.h"
#include "ui_lunchtimeslist.h"
#include "models.h"

LunchTimesList::LunchTimesList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LunchTimesList)
{
    ui->setupUi(this);
}

LunchTimesList::~LunchTimesList()
{
    delete ui;
}



void LunchTimesList::on_lunchTimesListWidget_clicked(const QModelIndex &index)
{

    GlobalVariables::Instance().setCurrentTrapeza(ui->lunchTimesListWidget->currentItem()->text());

    GlobalVariables::Instance().dishsByTimeForm()->readModel(ui->dayEdit->text(),
                                                                      ui->lunchTimesListWidget->currentItem()->text());
    GlobalVariables::Instance().dishsByTimeForm()->show();
}

void LunchTimesList::on_toMainButton_clicked()
{
    GlobalVariables::Instance().mainWindow()->show();
    hide();
}

void LunchTimesList::on_calendarButton_clicked()
{
  GlobalVariables::Instance().farPlannerForm()->show();
}

void LunchTimesList::showEvent(QShowEvent *event)
{
    ui->dayEdit->setText(GlobalVariables::Instance().currentDay());
}


void LunchTimesList::setCurrentDay(const QString &day) {
  ui->dayEdit->setText(day);
}
