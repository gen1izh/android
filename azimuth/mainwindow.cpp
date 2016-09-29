#include "mainwindow.h"
#include "ui_mainwindow.h"



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

  m_model = new PointsModel;

  ui->pointsBox->addItems(m_model->showAllPointsNames());

  QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
  if (source) {
      connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
              this, SLOT(positionUpdated(QGeoPositionInfo)));
      source->startUpdates();
  }

  connect(&m_tick, SIGNAL(timeout()), this, SLOT(updateDistanceInfo()));


}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::positionUpdated(const QGeoPositionInfo &info) {
    ui->currentCoordinates->setText(QString("Широта: %1 Долгота: %1").arg(info.coordinate().latitude()).arg(info.coordinate().longitude()));
    m_info = info;
}

void MainWindow::updateDistanceInfo()
{
    QGeoCoordinate current;
    double latitude = m_model->getLatitudeByPointName(ui->pointsBox->currentText());
    double longitude = m_model->getLongitudeByPointName(ui->pointsBox->currentText());
    current.setLatitude(latitude);
    current.setLongitude(longitude);

    ui->lcdNumber->display(current.distanceTo(m_info.coordinate()));

    ui->angleNumber->display(current.azimuthTo(m_info.coordinate()));


    QString  info = QString("Const lat %1 long %2 ; New lat %3 long %4").arg(latitude)
            .arg(longitude).arg(m_info.coordinate().latitude()).arg(m_info.coordinate().longitude());

    ui->infoEdit->setText(info);
}

void MainWindow::on_setPointButton_clicked()
{

  m_model->createNewPoint(ui->pointNameEdit->text(),
                          QString("%1").arg(m_info.coordinate().latitude()),
                          QString("%1").arg(m_info.coordinate().longitude()));
  ui->pointsBox->clear();
  ui->pointsBox->addItems(m_model->showAllPointsNames());
}

void MainWindow::on_startButton_clicked()
{
  if (ui->pointsBox->currentText().isEmpty()) {
    QMessageBox msg;
    msg.setText("Вы не выбрали точку начала");
    msg.show();
    return;
  }


  if (ui->startButton->text() == "Начать") {
    ui->startButton->setText("Приостановить");
    m_tick.start(1000);
    ui->pointsBox->setEnabled(false);
    ui->setPointButton->setEnabled(false);
  }
  else {
    ui->startButton->setText("Начать");
    ui->lcdNumber->display(-1);
    ui->angleNumber->display(-1);
    m_tick.stop();
     ui->pointsBox->setEnabled(true);
     ui->setPointButton->setEnabled(true);
  }
}

