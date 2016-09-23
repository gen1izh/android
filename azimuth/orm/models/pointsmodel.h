#ifndef POINTS_MODEL_H
#define POINTS_MODEL_H

#include <QStringListModel>
#include <QtSql/QSqlDatabase>

class PointsModel
{

  QSqlDatabase m_db;

public:
  PointsModel();
  ~PointsModel();

  QStringList showAllPointsNames();

  void createNewPoint(const QString &name, const QString &latitude, const QString &longtitude);

  double getLatitudeByPointName(const QString &name);
  double getLongitudeByPointName(const QString &name);

};

#endif // POINTS_MODEL_H
