
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "purposeqdjangomodel.h"
#include "purposemodel.h"

#include <QMessageBox>

PurposeModel::PurposeModel()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("taskmanager");
    m_db.open();

    QDjango::setDatabase(m_db);
    QDjango::registerModel<Purpose>();

    QDjango::createTables();
}

PurposeModel::~PurposeModel()
{
    m_db.close();
}

QStringList PurposeModel::showAllPointsNames()
{

    QStringList list;

//    QDjangoQuerySet<PositionPoints> points;

//    QList<QVariantMap> propertyMaps = points.values(QStringList() << "name" << "longtitude" << "latitude");
//    foreach (const QVariantMap &propertyMap, propertyMaps) {
//        list.append(propertyMap["name"].toString());
//    }

    return list;
}




