#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtPositioning/QGeoPositionInfo>
#include <QtPositioning/QGeoPositionInfoSource>

#include <QFile>
#include <QDir>
#include <QTextStream>

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

    createHtml();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_treksModel;

    delete m_pointsModel;
}

void MainWindow::createHtml()
{
    QFile data("map.html");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << "<!DOCTYPE html>\n";
        out << "<html>\n";
        out << "<head>\n";
        out << "    <title>Trekker</title>\n";
        out << "    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n";
        out << "    <script src=\"https://api-maps.yandex.ru/2.0/?load=package.standard,package.geoObjects&lang=ru-RU\" type=\"text/javascript\"></script>\n";
        out << "    <script src=\"map.js\" type=\"text/javascript\"></script>\n";
        out << "</head>\n";
        out << "<body>\n";
        out << "    <div id=\"map\" style=\"width:1080px; height:1920px\"></div>\n";
        out << "</body>\n";
        out << "</html>\n";
    }
    data.close();
}

void MainWindow::createJs()
{
    QFile data("map.js");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);

        out << "ymaps.ready(init);\n";
        out << "function init() {\n";
        out << "    // Создаем карту.\n";
        out << "    var myMap = new ymaps.Map(\"map\", {\n";
        out << "            center: [55.72, 37.44],\n";
        out << "            zoom: 15\n";
        out << "        });\n";
        out << "    // Создаем ломаную с помощью вспомогательного класса Polyline.\n";
        out << "    var myPath = new ymaps.Polyline([\n";
        out << "            // Указываем координаты вершин ломаной.\n";
        out << "            [55.80, 37.50],\n";
        out << "            [55.90, 37.30],\n";
        out << "            [55.60, 37.20],\n";
        out << "            [55.80, 37.10]\n";
        out << "        ], {\n";
        out << "            // Описываем свойства геообъекта.\n";
        out << "            // Содержимое балуна.\n";
        out << "            balloonContent: \"Траектория маршрута\"\n";
        out << "        }, {\n";
        out << "            // Задаем опции геообъекта.\n";
        out << "            // Отключаем кнопку закрытия балуна.\n";
        out << "            balloonCloseButton: false,\n";
        out << "            // Цвет линии.\n";
        out << "            strokeColor: \"#000000\",\n";
        out << "            // Ширина линии.\n";
        out << "            strokeWidth: 2,\n";
        out << "            // Коэффициент прозрачности.\n";
        out << "            strokeOpacity: 1\n";
        out << "        });\n";
        out << "            // Создаем метку с помощью вспомогательного класса.\n";
        out << "        myPlace = new ymaps.Placemark([55.80, 37.50], {\n";
        out << "            // Свойства.\n";
        out << "            // Содержимое иконки, балуна и хинта.\n";
        out << "            iconContent: '1',\n";
        out << "            balloonContent: 'Точка местоположения',\n";
        out << "            hintContent: 'Метка'\n";
        out << "        }, {\n";
        out << "            // Опции.\n";
        out << "            // Стандартная фиолетовая иконка.\n";
        out << "            preset: 'twirl#violetIcon'\n";
        out << "        });\n";
        out << "    // Добавляем линии на карту.\n";
        out << "    myMap.geoObjects.add(myPath);\n";
        out << "    myMap.geoObjects.add(myPlace);\n";
        out << "    myMap.controls.add('scaleLine');\n";
        out << "    myMap.controls.add('zoomControl');\n";
        out << "    myMap.controls.add('typeSelector');\n";
        out << "}\n";

    }

    data.close();

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
    bool ok;

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

    updateMapTickTimerSlot();
    updatePositionTickTimerSlot();


    m_updateMapTickTimer.start(m_updateMapTickValueBox.toInt(&ok,10)*1000);
    m_updatePositionTickTimer.start(m_updatePositionTickValueBox.toInt(&ok,10)*1000);
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
    createJs();

    //    if ((m_latitude == 0) && (m_longitude == 0)) {
    //        return;
    //    }

    m_pointsModel->createNewPoint(m_currentTrek, m_latitude, m_longitude);

    QString path = QDir::currentPath() + "/map.html";

    // Загружаем страницу по заданном URL в поле lineEdit
    //ui->mapView->load(QUrl::fromLocalFile(path));
}


void MainWindow::positionUpdated(const QGeoPositionInfo &info) {
    m_latitude  = info.coordinate().latitude();
    m_longitude = info.coordinate().longitude();
}
