#include "mainwindow.h"
#include <QApplication>

#include "commonsharedsingleton.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;

  CommonSharedSingleton::instance();

  w.show();

  return a.exec();
}
