#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QThread>
#include <QScreen>
#include "models.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    GlobalVariables::Instance();

    QApplication::primaryScreen()->setOrientationUpdateMask(Qt::PortraitOrientation);

    w.setSplashPlay(true);

    QPixmap pixmap(":/images/img/splash.png");
    QSplashScreen *_splash = new QSplashScreen();
    _splash->setPixmap(pixmap);
    _splash->show();

    while(w.splashPlay()){
        QThread::msleep(1000);
        w.setSplashPlay(false);
    }

    _splash->finish(&w);
    delete _splash;


//    QCoreApplication::setOrganizationName("DinnerPlanner");
//    QCoreApplication::setOrganizationDomain("home");
//    QCoreApplication::setApplicationName("DinnerPlanner");

    w.show();

    return a.exec();
}
