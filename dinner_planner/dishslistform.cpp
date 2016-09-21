#include "dishslistform.h"
#include "ui_dishslistform.h"
#include "models.h"
#include "dishsbytimeform.h"

DishsListForm::DishsListForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DishsListForm)
{
    ui->setupUi(this);

    GlobalVariables::Instance().setDishListModel(new DishListModel());

    ui->dishsListView->setModel(GlobalVariables::Instance().dishListModel());

}



DishsListForm::~DishsListForm()
{
    delete ui;
    delete GlobalVariables::Instance().dishListModel();
}

void DishsListForm::on_dishsListView_clicked(const QModelIndex &index)
{

    GlobalVariables::Instance().dishsByDayModel()->addDish(ui->dayLabel->text(),
                                                           ui->trapezaLabel->text(),
                                                           index.data().toString());


    GlobalVariables::Instance().dishsByTimeForm()->readModel(ui->dayLabel->text(),
                                                            ui->trapezaLabel->text());
    GlobalVariables::Instance().dishsByTimeForm()->show();
    hide();
}

void DishsListForm::on_toMainButton_clicked()
{
    GlobalVariables::Instance().mainWindow()->show();
    hide();
}


void DishsListForm::showEvent(QShowEvent *event)
{
    ui->dayLabel->setText(GlobalVariables::Instance().currentDay());
    ui->trapezaLabel->setText(GlobalVariables::Instance().currentTrapeza());
}


void DishsListForm::setCurrentDay(const QString &day) {
  ui->dayLabel->setText(day);
}

void DishsListForm::on_backButton_clicked()
{
    hide();
}
