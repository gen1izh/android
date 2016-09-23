#include "pointsqdjangomodel.h"


QString PositionPoints::latitude() const
{
  return m_latitude;
}

void PositionPoints::setLatitude(const QString &latitude)
{
  m_latitude = latitude;
}
QString PositionPoints::name() const
{
  return m_name;
}

void PositionPoints::setName(const QString &name)
{
  m_name = name;
}
QString PositionPoints::longtitude() const
{
  return m_longtitude;
}

void PositionPoints::setLongtitude(const QString &longtitude)
{
  m_longtitude = longtitude;
}




