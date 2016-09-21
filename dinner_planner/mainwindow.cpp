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
}


void MainWindow::positionUpdated(const QGeoPositionInfo &info) {
    ui->shitotaLabel->setText(QString("Широта: %1").arg(info.coordinate().latitude()));
    ui->dolgotaLabel->setText(QString("Долгота: %1").arg(info.coordinate().longitude()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createNewFoodMenuButton_clicked()
{
    GlobalVariables::Instance().newDishForm()->show();
}

void MainWindow::on_monButton_clicked()
{
    GlobalVariables::Instance().lunchTimesList()->setDay(ui->monLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_tueButton_clicked()
{
    GlobalVariables::Instance().lunchTimesList()->setDay(ui->tueLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_wedButton_clicked()
{
    GlobalVariables::Instance().lunchTimesList()->setDay(ui->wedLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_thuButton_clicked()
{
    GlobalVariables::Instance().lunchTimesList()->setDay(ui->thuLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_friButton_clicked()
{
    GlobalVariables::Instance().lunchTimesList()->setDay(ui->friLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_satButton_clicked()
{
    GlobalVariables::Instance().lunchTimesList()->setDay(ui->satLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}

void MainWindow::on_sunButton_clicked()
{
    GlobalVariables::Instance().lunchTimesList()->setDay(ui->sunLabel->text());
    GlobalVariables::Instance().lunchTimesList()->show();
}
