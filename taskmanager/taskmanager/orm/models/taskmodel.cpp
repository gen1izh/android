
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "taskqdjangomodel.h"
#include "taskmodel.h"

#include <QMessageBox>

TaskModel::TaskModel()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("taskmanager");
    m_db.open();

    QDjango::setDatabase(m_db);
    QDjango::registerModel<Task>();

    QDjango::createTables();
}

TaskModel::~TaskModel()
{
    m_db.close();
}

QStringList TaskModel::showAllPointsNames()
{

    QStringList list;

//    QDjangoQuerySet<Task> points;

//    QList<QVariantMap> propertyMaps = points.values(QStringList() << "name" << "longtitude" << "latitude");
//    foreach (const QVariantMap &propertyMap, propertyMaps) {
//        list.append(propertyMap["name"].toString());
//    }

    return list;
}

void TaskModel::addNewTask(const QString &name, const QString &description, const QString &date)
{

}

void TaskModel::editTask(int id, const QString &name, const QString &description, const QString &date, const QString &status, const QString &results)
{

}


