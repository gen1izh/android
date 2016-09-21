#include "dishsbytimeform.h"
#include "ui_dishsbytimeform.h"


#include "dishslistform.h"

#include "models.h"

DishsByTimeForm::DishsByTimeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DishsByTimeForm)
{
    ui->setupUi(this);

    GlobalVariables::Instance().setDishsByDayModel(new DishsByDayModel());

    ui->dishsByDayListView->setModel(GlobalVariables::Instance().dishsByDayModel());
}

DishsByTimeForm::~DishsByTimeForm()
{
    delete ui;
}

void DishsByTimeForm::readModel(const QString &day, const QString &lunchTime)
{
    GlobalVariables::Instance().dishsByDayModel()->updateModel(day, lunchTime);
}


void DishsByTimeForm::on_addButton_clicked()
{
    GlobalVariables::Instance().dishsListForm()->setDay(ui->dayLabel->text());
    GlobalVariables::Instance().dishsListForm()->setTrapeza(ui->trapezaLabel->text());
    GlobalVariables::Instance().dishListModel()->updateModel();
    GlobalVariables::Instance().dishsListForm()->show();
    hide();
}

void DishsByTimeForm::setDay(const QString &day) {
    ui->dayLabel->setText(day);
}

void DishsByTimeForm::setTrapeza(const QString &trapeza) {
    ui->trapezaLabel->setText(trapeza);
}


void DishsByTimeForm::on_deleteButton_clicked()
{
    GlobalVariables::Instance().dishsByDayModel()->deleteDish(ui->dayLabel->text(),
                                                     ui->trapezaLabel->text(),
                                                     ui->dishsByDayListView->currentIndex().data().toString());
}

void DishsByTimeForm::on_toMainButton_clicked()
{
    GlobalVariables::Instance().mainWindow()->show();
    hide();
}
