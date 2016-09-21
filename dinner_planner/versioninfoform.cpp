#include "versioninfoform.h"
#include "ui_versioninfoform.h"
#include <QDir>
#include <QSettings>

VersionInfoForm::VersionInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VersionInfoForm)
{
    ui->setupUi(this);
    QString info = QString("Текущий путь до программы: %1 \n").arg(QDir::currentPath());

    bool ok;
    QSettings settings("Home", "DinnerPlanner");
    settings.beginGroup("gps_coordinates");
    double lat   = settings.value("latitude", -1).toDouble(&ok);
    double longi = settings.value("longitude", -1).toDouble(&ok);
    settings.endGroup();


    info += QString("Координаты дома. Широта: %1, долгота: %2 \n").arg(lat).arg(longi);

    ui->informationEdit->setText(info);
}

VersionInfoForm::~VersionInfoForm()
{
    delete ui;
}

void VersionInfoForm::on_toMainButton_clicked()
{
    hide();
}
