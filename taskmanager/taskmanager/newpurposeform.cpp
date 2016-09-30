#include "newpurposeform.h"
#include "ui_newpurposeform.h"

NewPurposeForm::NewPurposeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPurposeForm)
{
    ui->setupUi(this);

    m_purposeModel = new PurposeModel();

    ui->purposeEdit->setPlainText(m_purposeModel->showPurposeOnCurrentMonth());

}

NewPurposeForm::~NewPurposeForm()
{
    delete ui;
}

void NewPurposeForm::on_saveButton_clicked()
{
    m_purposeModel->setPurposeOnCurrentMonth(ui->purposeEdit->toPlainText());
}
