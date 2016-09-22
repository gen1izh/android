
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "treksqdjangomodel.h"
#include "treksmodel.h"
#include <QMessageBox>


TreksModel::TreksModel()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("trekker");
    m_db.open();

    QDjango::setDatabase(m_db);
    QDjango::registerModel<Treks>();

    QDjango::createTables();
}

TreksModel::~TreksModel()
{
    m_db.close();
}

void TreksModel::instanceTrek(const QString &name) {

    bool is_Find = false;
    QDjangoQuerySet<Treks> treks;
    QList<QVariantMap> propertyMaps = treks.values(QStringList() << "name");
    foreach (const QVariantMap &propertyMap, propertyMaps) {
        if (name == propertyMap["name"].toString()) {
            is_Find = true;
        }
    }

    if (!is_Find) {
        Treks *trek = new Treks;
        trek->setName(name);
        trek->save();
    }

}

QStringList TreksModel::showTreks() {

    QStringList tmp;

    QDjangoQuerySet<Treks> treks;
    QList<QVariantMap> propertyMaps = treks.values(QStringList() << "name");
    foreach (const QVariantMap &propertyMap, propertyMaps) {
        tmp.append(propertyMap["name"].toString());
    }

    return tmp;
}
