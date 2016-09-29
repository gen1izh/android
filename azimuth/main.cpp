#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;

  w.setSplashPlay(true);
  QPixmap pixmap(":/img/splash.png");
  QSplashScreen *_splash = new QSplashScreen();
  _splash->setPixmap(pixmap);
  _splash->show();

  while(w.splashPlay()){
      QThread::msleep(1000);
      w.setSplashPlay(false);
  }

  _splash->finish(&w);
  delete _splash;

  w.show();

  return a.exec();
}
