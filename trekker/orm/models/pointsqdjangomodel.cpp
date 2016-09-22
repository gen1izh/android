#include "pointsqdjangomodel.h"

QString PositionPoints::trekName() const
{
  return m_trekName;
}

void PositionPoints::setTrekName(const QString &trekName)
{
  m_trekName = trekName;
}
double PositionPoints::longtitude() const
{
  return m_longtitude;
}

void PositionPoints::setLongtitude(const double &longtitude)
{
  m_longtitude = longtitude;
}
double PositionPoints::latitude() const
{
  return m_latitude;
}

void PositionPoints::setLatitude(const double &latitude)
{
  m_latitude = latitude;
}


