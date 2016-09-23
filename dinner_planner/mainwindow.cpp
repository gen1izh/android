#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "models.h"



bool MainWindow::splashPlay() const
{
    return m_splashPlay;
}

void MainWindow::setSplashPlay(bool splashPlay)
{
    m_splashPlay = splashPlay;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    if (source) {
        connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(positionUpdated(QGeoPositionInfo)));
        source->startUpdates();
    }

    GlobalVariables::Instance().InitializeForms();

    GlobalVariables::Instance().setMainWindowPointer(this);

    QDateTime now = QDateTime::currentDateTime();

    if (now.date().dayOfWeek() > Qt::Monday) {
        int days = 7 - (now.date().dayOfWeek() - Qt::Monday);
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->monLabel->setText(newDate.toString("dd.MM.yyyy"));
    }
    else {
        int days = Qt::Monday - now.date().dayOfWeek();
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->monLabel->setText(newDate.toString("dd.MM.yyyy"));
    }

    if (now.date().dayOfWeek() > Qt::Tuesday) {
        int days = 7 - (now.date().dayOfWeek() - Qt::Tuesday);
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->tueLabel->setText(newDate.toString("dd.MM.yyyy"));
    }
    else {
        int days = Qt::Tuesday - now.date().dayOfWeek();
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->tueLabel->setText(newDate.toString("dd.MM.yyyy"));
    }

    if (now.date().dayOfWeek() > Qt::Wednesday) {
        int days = 7 - (now.date().dayOfWeek() - Qt::Wednesday);
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->wedLabel->setText(newDate.toString("dd.MM.yyyy"));
    }
    else {
        int days = Qt::Wednesday - now.date().dayOfWeek();
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->wedLabel->setText(newDate.toString("dd.MM.yyyy"));
    }

    if (now.date().dayOfWeek() > Qt::Thursday) {
        int days = 7 - (now.date().dayOfWeek() - Qt::Thursday);
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->thuLabel->setText(newDate.toString("dd.MM.yyyy"));
    }else {
        int days = Qt::Thursday - now.date().dayOfWeek();
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->thuLabel->setText(newDate.toString("dd.MM.yyyy"));
    }

    if (now.date().dayOfWeek() > Qt::Friday) {
        int days = 7 - (now.date().dayOfWeek() - Qt::Friday);
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->friLabel->setText(newDate.toString("dd.MM.yyyy"));
    }else {
        int days = Qt::Friday - now.date().dayOfWeek();
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->friLabel->setText(newDate.toString("dd.MM.yyyy"));
    }

    if (now.date().dayOfWeek() > Qt::Saturday) {
        int days = 7 - (now.date().dayOfWeek() - Qt::Saturday);
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->satLabel->setText(newDate.toString("dd.MM.yyyy"));
    }
    else {
        int days = Qt::Saturday - now.date().dayOfWeek();
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->satLabel->setText(newDate.toString("dd.MM.yyyy"));
    }

    if (now.date().dayOfWeek() > Qt::Sunday) {
        int days = 7 - (now.date().dayOfWeek() - Qt::Sunday);
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->sunLabel->setText(newDate.toString("dd.MM.yyyy"));
    }
    else {
        int days = Qt::Sunday - now.date().dayOfWeek();
        QDateTime newDate(QDate(now.date().year(), now.date().month(), now.date().day()+days), QTime(0, 0));
        ui->sunLabel->setText(newDate.toString("dd.MM.yyyy"));
    }

    bool ok;
    QSettings settings("Home", "DinnerPlanner");
    settings.beginGroup("gps_coordinates");
    double lat   = settings.value("latitude", -1).toDouble(&ok);
    double longi = settings.value("longitude", -1).toDouble(&ok);
    settings.endGroup();

    if ((lat =-1) && (longi == -1)) {
        ui->setXyTab->setVisible(true);
        ui->resetXyTab->setVisible(false);
    }
    else {
        ui->setXyTab->setVisible(false);
        ui->resetXyTab->setVisible(true);
    }
    QGeoAreaMonitorSource *monitor = QGeoAreaMonitorSource::createDefaultSource(this);
    if (monitor) {
        connect(monitor, SIGNAL(areaEntered(QGeoAreaMonitorInfo,QGeoPositionInfo)),
                this, SLOT(areaEntered(QGeoAreaMonitorInfo,QGeoPositionInfo)));
        connect(monitor, SIGNAL(areaExited(QGeoAreaMonitorInfo,QGeoPositionInfo)),
                this, SLOT(areaExited(QGeoAreaMonitorInfo,QGeoPositionInfo)));

        QGeoAreaMonitorInfo homePlace("Home");
        QGeoCoordinate position(lat, longi);
        homePlace.setArea(QGeoCircle(position, 100));

        monitor->startMonitoring(homePlace);

    } else {
        QMessageBox msgBox;
        msgBox.setText("Could not create default area monitor");
        msgBox.exec();
    }

    ui->statusPositionLabel->setText("Видимо проблемы с Gps... Ниче не вижу.");
}


void MainWindow::positionUpdated(const QGeoPositionInfo &info) {
    ui->shitotaLabel->setText(QString("Широта: %1").arg(info.coordinate().latitude()));
    ui->dolgotaLabel->setText(QString("Долгота: %1").arg(info.coordinate().longitude()));

    latitude = info.coordinate().latitude();
    longitude = info.coordinate().longitude();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createNewFoodMenuButton_clicked()
{
    GlobalVariables::Instance().newDishForm()->clearEdits();
    GlobalVariables::Instance().newDishForm()->show();
}

void MainWindow::on_monButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->monLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_tueButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->tueLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_wedButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->wedLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_thuButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->thuLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_friButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->friLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_satButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->satLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_sunButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->sunLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_setCoordinateButton_clicked()
{
    QSettings settings("Home", "DinnerPlanner");
    settings.beginGroup("gps_coordinates");
    settings.setValue("latitude", latitude);
    settings.setValue("longitude", longitude);
    settings.endGroup();

    ui->setXyTab->setVisible(false);
    ui->resetXyTab->setVisible(true);

}

void MainWindow::on_resetCoordinateButton_clicked()
{
    QSettings settings("Home", "DinnerPlanner");
    settings.beginGroup("gps_coordinates");
    settings.setValue("latitude", -1);
    settings.setValue("longitude", -1);
    settings.endGroup();

    ui->setXyTab->setVisible(true);
    ui->resetXyTab->setVisible(false);
}

void MainWindow::areaEntered(const QGeoAreaMonitorInfo &mon, const QGeoPositionInfo &update)
{
  Q_UNUSED(mon)
    ui->statusPositionLabel->setText(QString("В доме, позиция: %1")
                                     .arg(update.coordinate().toString(QGeoCoordinate::Degrees)));

}

void MainWindow::areaExited(const QGeoAreaMonitorInfo &mon, const QGeoPositionInfo &update)
{
  Q_UNUSED(mon)

    ui->statusPositionLabel->setText(QString("Вне дома, позиция: %1")
                                     .arg(update.coordinate().toString(QGeoCoordinate::Degrees)));
}

void MainWindow::on_monBasketButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->monLabel->text());
    GlobalVariables::Instance().basketForm()->show();
}

void MainWindow::on_tueBasketButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->tueLabel->text());
    GlobalVariables::Instance().basketForm()->show();
}

void MainWindow::on_wedBasketButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->wedLabel->text());
    GlobalVariables::Instance().basketForm()->show();
}

void MainWindow::on_thuBasketButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->thuLabel->text());
    GlobalVariables::Instance().basketForm()->show();
}

void MainWindow::on_friBasketButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->friLabel->text());
    GlobalVariables::Instance().basketForm()->show();
}

void MainWindow::on_satBasketButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->satLabel->text());
    GlobalVariables::Instance().basketForm()->show();
}

void MainWindow::on_sunBasketButton_clicked()
{
    GlobalVariables::Instance().setCurrentDay(ui->sunLabel->text());
    GlobalVariables::Instance().basketForm()->show();
}

void MainWindow::on_versionButton_clicked()
{
    GlobalVariables::Instance().versionInfoForm()->show();
}
