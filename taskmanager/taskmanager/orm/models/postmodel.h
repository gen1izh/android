#ifndef POST_MODEL_H
#define POST_MODEL_H

#include <QStringListModel>
#include <QtSql/QSqlDatabase>

class PostModel
{

  QSqlDatabase m_db;

public:
  PostModel();
  ~PostModel();

  QStringList showAllPointsNames();

};

#endif // POST_MODEL_H
