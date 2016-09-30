
#include "../db/QDjango.h"
#include "../db/QDjangoQuerySet.h"

#include "purposeqdjangomodel.h"
#include "purposemodel.h"

#include <QMessageBox>
#include <QDate>

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

QString PurposeModel::showPurposeOnCurrentMonth() {

    QString purpose;

    purpose.clear();

    QDjangoQuerySet<Purpose> purps;

    QList<QVariantMap> propertyMaps = purps.values(QStringList() << "monthYear" << "purpose");
    foreach (const QVariantMap &propertyMap, propertyMaps) {
        purpose = propertyMap["monthYear"].toString();

        QStringList tmp = purpose.split(".");

        // MM
        if (tmp.at(0) == QDate::currentDate().toString("MM")) {
            // yyyy
            if (tmp.at(1) == QDate::currentDate().toString("yyyy")) {
                return propertyMap["purpose"].toString();
            }
        }


    }

    return purpose;
}

void PurposeModel::setPurposeOnCurrentMonth(QString purpose)
{

    QDjangoQuerySet<Purpose> somePurp;

    bool isFind = false;

    Purpose purp;
    for (int i = 0; i < somePurp.size(); ++i) {
        if (somePurp.at(i, &purp)) {

            QStringList tmp = (purp.monthYear()).split(".");

            // MM
            if (tmp.at(0) == QDate::currentDate().toString("MM")) {
                // yyyy
                if (tmp.at(1) == QDate::currentDate().toString("yyyy")) {

                    isFind = true;
                    break;
                }
            }

        }
    }


    if (isFind) {
        purp.setMonthYear(QDate::currentDate().toString("MM.yyyy"));
        purp.setPurpose(purpose);
        purp.save();
    }
    else {
        Purpose *purp = new Purpose;
        purp->setMonthYear(QDate::currentDate().toString("MM.yyyy"));
        purp->setPurpose(purpose);
        purp->save();
    }

}




