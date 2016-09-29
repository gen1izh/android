#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGeoPositionInfoSource>
#include <QGeoPositionInfo>
#include <QMessageBox>
#include <QTimer>

#include "orm/models/pointsmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

  PointsModel       *m_model;
  QGeoPositionInfo   m_info;
  QTimer m_tick;

  bool m_splashPlay;

   int iii= 0;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

public slots:
    void positionUpdated(const QGeoPositionInfo &info);

    void updateDistanceInfo();

    bool splashPlay() const;
    void setSplashPlay(bool splashPlay);
private slots:
    void on_setPointButton_clicked();
    void on_startButton_clicked();
};

#endif // MAINWINDOW_H
