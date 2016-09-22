#ifndef TREKS_MODEL_H
#define TREKS_MODEL_H

#include <QStringListModel>
#include <QtSql/QSqlDatabase>

class TreksModel
{

  QSqlDatabase m_db;

public:
  TreksModel();
  ~TreksModel();

  void instanceTrek(const QString &name);

  QStringList showTreks();
};

#endif // TREKS_MODEL_H
