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

void LunchTimesList::setDay(const QString &day)
{
    ui->dayEdit->setText(day);
}


void LunchTimesList::on_lunchTimesListWidget_clicked(const QModelIndex &index)
{
    GlobalVariables::Instance().dishsByTimeForm()->setDay(ui->dayEdit->text());
    GlobalVariables::Instance().dishsByTimeForm()->setTrapeza(ui->lunchTimesListWidget->currentItem()->text());
    GlobalVariables::Instance().dishsByTimeForm()->readModel(ui->dayEdit->text(),
                                                                      ui->lunchTimesListWidget->currentItem()->text());
    GlobalVariables::Instance().dishsByTimeForm()->show();
    hide();
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
