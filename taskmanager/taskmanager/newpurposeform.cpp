#include "newpurposeform.h"
#include "ui_newpurposeform.h"

#include "commonsharedsingleton.h"

NewPurposeForm::NewPurposeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPurposeForm)
{
    ui->setupUi(this);

    ui->purposeEdit->setPlainText(CommonSharedSingleton::instance().getPurposeModel()->showPurposeOnCurrentMonth());

}

NewPurposeForm::~NewPurposeForm()
{
    delete ui;
}

void NewPurposeForm::on_saveButton_clicked()
{
    CommonSharedSingleton::instance().getPurposeModel()->setPurposeOnCurrentMonth(ui->purposeEdit->toPlainText());
}
