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

  QList<QPair<double, double> > showTrekPointsByTrekId(const QString &trekName);

  void createNewPoint(const QString &trekName, const double &latitude, const double &longtitude);

};

#endif // POINTS_MODEL_H
