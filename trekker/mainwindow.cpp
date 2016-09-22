#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtPositioning/QGeoPositionInfo>
#include <QtPositioning/QGeoPositionInfoSource>

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


    m_treksModel = new TreksModel();
    m_pointsModel = new PointsModel();

    ui->treksBox->clear();

    ui->treksBox->addItems(m_treksModel->showTreks());

    connect(&m_updateMapTickTimer, SIGNAL(timeout()), this, SLOT(updateMapTickTimerSlot()));
    connect(&m_updatePositionTickTimer, SIGNAL(timeout()), this, SLOT(updatePositionTickTimerSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_treksModel;

    delete m_pointsModel;
}

void MainWindow::on_zoomBox_currentTextChanged(const QString &arg1)
{
    m_zoomBox = arg1;
}

void MainWindow::on_updateMapTickValueBox_currentTextChanged(const QString &arg1)
{
    m_updateMapTickValueBox = arg1;
}

void MainWindow::on_updatePositionTickValueBox_currentTextChanged(const QString &arg1)
{
    m_updatePositionTickValueBox = arg1;
}

void MainWindow::on_startButton_clicked()
{

    if (!ui->newTrekEdit->text().isEmpty()) {
        m_currentTrek = ui->newTrekEdit->text();
        ui->newTrekEdit->setText("");
        ui->treksBox->setCurrentText(m_currentTrek);
        m_treksModel->instanceTrek(m_currentTrek);
    }
    else {
        m_currentTrek = ui->treksBox->currentText();
        m_treksModel->instanceTrek(m_currentTrek);
    }

    bool ok;
    m_updateMapTickTimer.start(m_updateMapTickValueBox.toInt(&ok,10));
    m_updatePositionTickTimer.start(m_updatePositionTickValueBox.toInt(&ok,10));
}

void MainWindow::on_stopButton_clicked()
{
    m_updateMapTickTimer.stop();
    m_updatePositionTickTimer.stop();
}

void MainWindow::updateMapTickTimerSlot()
{
    // Просто перезагрузка карты
}

void MainWindow::updatePositionTickTimerSlot()
{
    if ((m_latitude == 0) && (m_longitude == 0)) {
        return;
    }

    m_pointsModel->createNewPoint(m_currentTrek, m_latitude, m_longitude);
}


void MainWindow::positionUpdated(const QGeoPositionInfo &info) {
    m_latitude  = info.coordinate().latitude();
    m_longitude = info.coordinate().longitude();
}
