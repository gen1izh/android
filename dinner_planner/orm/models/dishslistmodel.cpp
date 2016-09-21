
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "dishlistqdjangomodel.h"
#include "dishslistmodel.h"

#include <QMessageBox>

DishListModel::DishListModel()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("dishbase");
    m_db.open();

    QDjango::setDatabase(m_db);
    QDjango::registerModel<DishList>();

    QDjango::createTables();
}

DishListModel::~DishListModel()
{
    m_db.close();
}

QStringList DishListModel::showDishsList()
{
    QDjangoQuerySet<DishList> dishs;
    QStringList tmp;

    tmp.clear();

    QList<QVariantMap> propertyMaps = dishs.values(QStringList() << "name");
    foreach (const QVariantMap &propertyMap, propertyMaps) {
        tmp.append(propertyMap["name"].toString());
    }

    return tmp;
}

void DishListModel::createNewDish(QString name, QString description) {

    QDjangoQuerySet<DishList> dishs;

    bool isFind = false;

    QList<QVariantMap> propertyMaps = dishs.values(QStringList() << "name");
    foreach (const QVariantMap &propertyMap, propertyMaps) {
        if ( name == propertyMap["name"].toString()){
            isFind = true;
        }
    }
    if (!isFind) {
        DishList *dish = new DishList;
        dish->setName(name);
        dish->setDescription(description);
        dish->save();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Такое блюдо(название) уже существует!");
        msgBox.exec();
    }

}

void DishListModel::updateModel()
{
    setStringList(showDishsList());
}

void DishListModel::deleteDish(const QModelIndex &index)
{
    QString name = data(index, Qt::DisplayRole).toString();
    removeRows(0, 1, index);

    QDjangoQuerySet<DishList> dishs;
    dishs = dishs.filter(QDjangoWhere("name", QDjangoWhere::Equals, name));
    dishs.remove();
}
