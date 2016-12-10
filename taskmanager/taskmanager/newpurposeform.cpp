#include "newpurposeform.h"
#include "ui_newpurposeform.h"

#include "commonsharedsingleton.h"

#include <QTimer>

NewPurposeForm::NewPurposeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPurposeForm)
{
    ui->setupUi(this);

    QTimer::singleShot(10000, this, SLOT(openPurpose()));

}

NewPurposeForm::~NewPurposeForm()
{
    delete ui;
}

void NewPurposeForm::on_saveButton_clicked()
{
    CommonSharedSingleton::instance().getPurposeModel()->setPurposeOnCurrentMonth(ui->purposeEdit->toPlainText());
}

void NewPurposeForm::openPurpose()
{
    ui->purposeEdit->setPlainText(CommonSharedSingleton::instance().getPurposeModel()->showPurposeOnCurrentMonth());
}
