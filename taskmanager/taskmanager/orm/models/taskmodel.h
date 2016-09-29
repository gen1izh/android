#ifndef TASK_MODEL_H
#define TASK_MODEL_H

#include <QStringListModel>
#include <QtSql/QSqlDatabase>

class TaskModel
{

  QSqlDatabase m_db;

public:
  TaskModel();
  ~TaskModel();

  QStringList showAllPointsNames();


};

#endif // TASK_MODEL_H
