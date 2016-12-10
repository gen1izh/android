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

  void addNewTask(const QString &name, const QString &description,
                  const QString &date);

  void editTask(int id, const QString &name, const QString &description,
                const QString &date, const QString &status, const QString &results);

};

#endif // TASK_MODEL_H
