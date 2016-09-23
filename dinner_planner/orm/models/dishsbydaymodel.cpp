
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "dishmenubydayqdjangomodel.h"

#include "dishsbydaymodel.h"

#include <QMessageBox>
#include <QDebug>


DishsByDayModel::DishsByDayModel()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("dishbase");
    m_db.open();

    QDjango::setDatabase(m_db);
    QDjango::registerModel<DishMenuByDay>();

    QDjango::createTables();
}

DishsByDayModel::~DishsByDayModel()
{
    m_db.close();
}


QStringList DishsByDayModel::showDishMenuByDayAndLunch(const QString &day, const QString &lunchTime)
{
    QDjangoQuerySet<DishMenuByDay> dishs;
    QStringList tmp;

    tmp.clear();

    QList<QVariantMap> propertyMaps = dishs.values(QStringList() << "day" << "lunchTime" << "dishName");
    foreach (const QVariantMap &propertyMap, propertyMaps) {
        if ((day == propertyMap["day"].toString())&&(lunchTime == propertyMap["lunchTime"].toString())) {
            tmp.append(propertyMap["dishName"].toString());
        }
    }

    return tmp;
}

QStringList DishsByDayModel::showDishMenuByDay(const QString &day)
{
    QDjangoQuerySet<DishMenuByDay> dishs;
    QStringList tmp;

    tmp.clear();

    QList<QVariantMap> propertyMaps = dishs.values(QStringList() << "day" << "lunchTime" << "dishName");
    foreach (const QVariantMap &propertyMap, propertyMaps) {
        if (day == propertyMap["day"].toString()) {
            tmp.append(propertyMap["dishName"].toString());
        }
    }

    return tmp;
}

void DishsByDayModel::addDish(const QString &day, const QString &lunchTime, const QString &dishName) {


    QDjangoQuerySet<DishMenuByDay> dishs;

    bool isFind = false;

    QList<QVariantMap> propertyMaps = dishs.values(QStringList() << "day" << "lunchTime" << "dishName");
    foreach (const QVariantMap &propertyMap, propertyMaps) {

        if ((day == propertyMap["day"].toString())&&
            (lunchTime == propertyMap["lunchTime"].toString())&&
            (dishName == propertyMap["dishName"].toString())){
            isFind = true;
        }
    }

    if (!isFind) {
        DishMenuByDay *dish = new DishMenuByDay;
        dish->setDay(day);
        dish->setLunchTime(lunchTime);
        dish->setDishName(dishName);
        dish->save();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Такое блюдо(название) уже существует в списке на этот день!");
        msgBox.exec();
    }
}

void DishsByDayModel::updateModel(const QString &day, const QString &lunchTime)
{
    setStringList(showDishMenuByDayAndLunch(day, lunchTime));
}

void DishsByDayModel::deleteDish(const QString &day, const QString &lunchTime, const QString &dishName)
{
    QDjangoQuerySet<DishMenuByDay> dishs;


    // iterate over matching users
    DishMenuByDay dish;
    for (int i = 0; i < dishs.size(); ++i) {
      if (dishs.at(i, &dish)) {
        qDebug() << "day = " << dish.day() << " lunchTime = " << dish.lunchTime() << "dishName = " <<  dish.dishName();
        if ((dish.day() == day) && (dish.lunchTime() == lunchTime) && (dish.dishName() == dishName) ) {
            dish.remove();
        }
      }
    }

}
