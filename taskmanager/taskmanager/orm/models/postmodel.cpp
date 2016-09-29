
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "postqdjangomodel.h"
#include "postmodel.h"

#include <QMessageBox>

PostModel::PostModel()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("taskmanager");
    m_db.open();

    QDjango::setDatabase(m_db);
    QDjango::registerModel<Post>();

    QDjango::createTables();
}

PostModel::~PostModel()
{
    m_db.close();
}

QStringList PostModel::showAllPointsNames()
{

    QStringList list;

//    QDjangoQuerySet<Post> points;

//    QList<QVariantMap> propertyMaps = points.values(QStringList() << "name" << "longtitude" << "latitude");
//    foreach (const QVariantMap &propertyMap, propertyMaps) {
//        list.append(propertyMap["name"].toString());
//    }

    return list;
}

