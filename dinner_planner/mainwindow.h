#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGeoPositionInfoSource>
#include <QDateTime>
#include <QDebug>
#include <QGeoAreaMonitorInfo>
#include <QGeoAreaMonitorSource>
#include <QGeoCircle>
#include <QMessageBox>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    bool m_splashPlay;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    MainWindow() : QObject() {

//    }



public slots:
    void positionUpdated(const QGeoPositionInfo &info);

    bool splashPlay() const;
    void setSplashPlay(bool splashPlay);

private slots:

    void on_createNewFoodMenuButton_clicked();

    void on_monButton_clicked();
    void on_tueButton_clicked();
    void on_wedButton_clicked();
    void on_thuButton_clicked();
    void on_friButton_clicked();
    void on_satButton_clicked();
    void on_sunButton_clicked();

    void on_setCoordinateButton_clicked();

    void on_resetCoordinateButton_clicked();


    void on_monBasketButton_clicked();

    void on_tueBasketButton_clicked();

    void on_wedBasketButton_clicked();

    void on_thuBasketButton_clicked();

    void on_friBasketButton_clicked();

    void on_satBasketButton_clicked();

    void on_sunBasketButton_clicked();

    void on_versionButton_clicked();

public Q_SLOTS:
        void areaEntered(const QGeoAreaMonitorInfo &mon, const QGeoPositionInfo &update);

        void areaExited(const QGeoAreaMonitorInfo &mon, const QGeoPositionInfo &update);
private:
    Ui::MainWindow *ui;

    double latitude=0;
    double longitude=0;
};






#endif // MAINWINDOW_H
