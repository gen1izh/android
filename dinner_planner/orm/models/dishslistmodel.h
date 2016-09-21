#ifndef DISHS_LIST_MODEL_H
#define DISHS_LIST_MODEL_H
#include <QStringListModel>
#include <QtSql/QSqlDatabase>

class DishListModel : public QStringListModel
{

  QSqlDatabase m_db;

public:
  DishListModel();
  ~DishListModel();

  QStringList showDishsList();

  void createNewDish(QString name, QString description);
  void deleteDish(const QModelIndex &index);

  void updateModel();

  QString showIngridientsByDush(const QString &name);

};

#endif // DISHS_LIST_MODEL_H
