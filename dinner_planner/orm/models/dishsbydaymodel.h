#ifndef DISH_BY_DAY_MODEL_H
#define DISH_BY_DAY_MODEL_H
#include <QStringListModel>
#include <QtSql/QSqlDatabase>

class DishsByDayModel : public QStringListModel
{

  QSqlDatabase m_db;

public:
  DishsByDayModel();
  ~DishsByDayModel();

  QStringList showDishMenuByDay(const QString &day, const QString &lunchTime);

  void addDish(const QString &day, const QString &lunchTime, const QString &dishName);
  void deleteDish(const QString &day, const QString &lunchTime, const QString &dishName);

  void updateModel(const QString &day, const QString &lunchTime);

};

#endif // DISH_BY_DAY_MODEL_H
