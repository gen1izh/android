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

  QStringList showAllPointsNames();

};

#endif // PURPOSE_MODEL_H
