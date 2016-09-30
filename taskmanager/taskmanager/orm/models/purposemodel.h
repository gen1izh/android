#ifndef PURPOSE_MODEL_H
#define PURPOSE_MODEL_H

#include <QStringListModel>
#include <QtSql/QSqlDatabase>

class PurposeModel
{

    QSqlDatabase m_db;

public:
    PurposeModel();
    ~PurposeModel();

    QString showPurposeOnCurrentMonth();

    void setPurposeOnCurrentMonth(QString purpose);

};


#endif // PURPOSE_MODEL_H
