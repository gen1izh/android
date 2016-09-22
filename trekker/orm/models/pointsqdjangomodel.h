#ifndef POINTS_QDJANGO_MODEL_H
#define POINTS_QDJANGO_MODEL_H

#include "../db/QDjangoModel.h"

class PositionPoints : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString trekName READ trekName WRITE setTrekName)
    Q_PROPERTY(double longtitude READ longtitude WRITE setLongtitude)
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude)

    Q_CLASSINFO("trekName", "0")
    Q_CLASSINFO("longtitude", "max_length=50")
    Q_CLASSINFO("latitude", "max_length=50")

public:

  QString trekName() const;
  void setTrekName(const QString &trekName);

  double longtitude() const;
  void setLongtitude(const double &longtitude);

  double latitude() const;
  void setLatitude(const double &latitude);

private:
  QString   m_trekName;
  double    m_longtitude;
  double    m_latitude;
};

#endif // POINTS_QDJANGO_MODEL_H
