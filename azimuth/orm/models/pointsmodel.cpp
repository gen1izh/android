
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "pointsqdjangomodel.h"
#include "pointsmodel.h"

#include <QMessageBox>

PointsModel::PointsModel()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("azimuth");
    m_db.open();

    QDjango::setDatabase(m_db);
    QDjango::registerModel<PositionPoints>();

    QDjango::createTables();
}

PointsModel::~PointsModel()
{
    m_db.close();
}

QStringList PointsModel::showAllPointsNames()
{

    QStringList list;

    QDjangoQuerySet<PositionPoints> points;

    QList<QVariantMap> propertyMaps = points.values(QStringList() << "name" << "longtitude" << "latitude");
    foreach (const QVariantMap &propertyMap, propertyMaps) {
        list.append(propertyMap["name"].toString());
    }

    return list;
}



void PointsModel::createNewPoint(const QString &name, const QString &latitude, const QString &longtitude) {

    bool isFind = false;

    QDjangoQuerySet<PositionPoints> points;

    //    QList<QVariantMap> propertyMaps = points.values(QStringList() << "name" << "longtitude" << "latitude");
    //    foreach (const QVariantMap &propertyMap, propertyMaps) {
    //       if (name == propertyMap["name"].toString()) {
    //          isFind = true;
    //       }
    //    }

    PositionPoints point;
    for (int i = 0; i < points.size(); ++i) {
        if (points.at(i, &point)) {
            if (name == point.name()) {
                point.setLatitude(latitude);
                point.setLongtitude(longtitude);
                point.save();
                isFind = true;
            }
        }
    }

    if (!isFind) {
        PositionPoints *point = new PositionPoints;
        point->setName(name);
        point->setLatitude(latitude);
        point->setLongtitude(longtitude);
        point->save();
    }
}

double PointsModel::getLatitudeByPointName(const QString &name)
{
    QDjangoQuerySet<PositionPoints> points;
    PositionPoints point;
    bool ok;
    for (int i = 0; i < points.size(); ++i) {
        if (points.at(i, &point)) {
            if (name == point.name()) {
                return point.latitude().toDouble(&ok);
            }
        }
    }
}

double PointsModel::getLongitudeByPointName(const QString &name)
{
    QDjangoQuerySet<PositionPoints> points;
    PositionPoints point;
    bool ok;
    for (int i = 0; i < points.size(); ++i) {
        if (points.at(i, &point)) {
            if (name == point.name()) {
                return point.longtitude().toDouble(&ok);
            }
        }
    }
}

