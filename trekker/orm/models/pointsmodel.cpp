
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "pointsqdjangomodel.h"
#include "pointsmodel.h"

#include <QMessageBox>

PointsModel::PointsModel()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("trekker");
    m_db.open();

    QDjango::setDatabase(m_db);
    QDjango::registerModel<PositionPoints>();

    QDjango::createTables();
}

PointsModel::~PointsModel()
{
    m_db.close();
}

QList<QPair<double, double> > PointsModel::showTrekPointsByTrekId(const QString &trekName)
{

    QList<QPair<double, double> > list;
    bool ok;

    QDjangoQuerySet<PositionPoints> points;

    QList<QVariantMap> propertyMaps = points.values(QStringList() << "trekName" << "longtitude" << "latitude");
    foreach (const QVariantMap &propertyMap, propertyMaps) {

      QPair<double, double> tmp;

       if (trekName == propertyMap["trekName"].toString()) {
          tmp.first = propertyMap["longtitude"].toDouble(&ok);
          tmp.second = propertyMap["latitude"].toDouble(&ok);
       }


        list.append(tmp);
    }

    return list;
}



void PointsModel::createNewPoint(const QString &trekName, const double &latitude, const double &longtitude) {
    PositionPoints *point = new PositionPoints;
    point->setTrekName(trekName);
    point->setLatitude(latitude);
    point->setLongtitude(longtitude);
    point->save();

}

