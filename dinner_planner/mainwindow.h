#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGeoPositionInfoSource>
#include <QDateTime>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
