#ifndef POINTS_QDJANGO_MODEL_H
#define POINTS_QDJANGO_MODEL_H

#include "../db/QDjangoModel.h"

class PositionPoints : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString longtitude READ longtitude WRITE setLongtitude)
    Q_PROPERTY(QString latitude READ latitude WRITE setLatitude)

    Q_CLASSINFO("name", "max_length=50")
    Q_CLASSINFO("longtitude", "max_length=50")
    Q_CLASSINFO("latitude", "max_length=50")

public:

  QString latitude() const;
  void setLatitude(const QString &latitude);

  QString name() const;
  void setName(const QString &name);

  QString longtitude() const;
  void setLongtitude(const QString &longtitude);

private:
  QString   m_name;
  QString   m_longtitude;
  QString   m_latitude;
};

#endif // POINTS_QDJANGO_MODEL_H
