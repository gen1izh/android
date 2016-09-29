#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <orm/models/treksmodel.h>
#include <orm/models/pointsmodel.h>

#include <QtPositioning/QGeoPositionInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void createHtml();
    void createJs();

private slots:
    void on_zoomBox_currentTextChanged(const QString &arg1);

    void on_updateMapTickValueBox_currentTextChanged(const QString &arg1);

    void on_updatePositionTickValueBox_currentTextChanged(const QString &arg1);

    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;

    QString m_zoomBox;

    QString m_updateMapTickValueBox;

    QString m_updatePositionTickValueBox;

    QTimer m_updateMapTickTimer;

    QTimer m_updatePositionTickTimer;

    QString m_currentTrek = "";

    TreksModel *m_treksModel;

    PointsModel *m_pointsModel;

    double  m_latitude = 0;
    double m_longitude = 0;

public slots:

    void updateMapTickTimerSlot();
    void updatePositionTickTimerSlot();

    void positionUpdated(const QGeoPositionInfo &info);

};

#endif // MAINWINDOW_H
