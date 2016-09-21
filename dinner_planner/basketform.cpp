#include "basketform.h"
#include "ui_basketform.h"
#include "models.h"

BasketForm::BasketForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::BasketForm)
{
  ui->setupUi(this);
}

BasketForm::~BasketForm()
{
  delete ui;
}

void BasketForm::on_toMainButton_clicked()
{
    hide();
}

void BasketForm::showEvent(QShowEvent *event)
{

    ui->reportEdit->setText("");
    QString text="";

    QStringList menuByDay =
            GlobalVariables::Instance().dishsByDayModel()->showDishMenuByDay(GlobalVariables::Instance().currentDay());

    text = "Список блюд на день и их ингридиенты:\n\n";

    foreach (const QString &dish, menuByDay) {
        text += "Блюдо: " + dish + " \n";
        text += "Ингридиенты: " +GlobalVariables::Instance().dishListModel()->showIngridientsByDush(dish) + " \n";
        text += " \n";
    }
    ui->reportEdit->setText(text);
}
