#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  // Настройка кодировки приложения
  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
  w.show();

  return a.exec();
}
