#include "newdishform.h"
#include "ui_newdishform.h"

#include "models.h"



NewDishForm::NewDishForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewDishForm)
{
    ui->setupUi(this);
}

NewDishForm::~NewDishForm()
{
    delete ui;
}

void NewDishForm::on_saveButton_clicked()
{
    GlobalVariables::Instance().dishListModel()->createNewDish(
                ui->nameLineEdit->text(),
                ui->descriptionTextEdit->toPlainText());

    GlobalVariables::Instance().dishListModel()->updateModel();

    hide();

}

void NewDishForm::on_toMainButton_clicked()
{
    GlobalVariables::Instance().mainWindow()->show();
    hide();
}


