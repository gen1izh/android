#ifndef DISH_MENU_BY_DAY_QDJANGO_MODEL_H
#define DISH_MENU_BY_DAY_QDJANGO_MODEL_H

#include "../db/QDjangoModel.h"

class DishMenuByDay : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString day READ day WRITE setDay)
    Q_PROPERTY(QString lunchTime READ lunchTime WRITE setLunchTime)
    Q_PROPERTY(QString dishName READ dishName WRITE setDishName)

    Q_CLASSINFO("day", "max_length=50")
    Q_CLASSINFO("dishName", "max_length=50")
    Q_CLASSINFO("lunchTime", "max_length=50")

public:
    QString day() const;
    void setDay(const QString &day);

    QString dishName() const;
    void setDishName(const QString &dishName);

    QString lunchTime() const;
    void setLunchTime(const QString &lunchTime);

private:
    QString m_day;
    QString m_dishName;
    QString m_lunchTime;
};

#endif // DISH_MENU_BY_DAY_QDJANGO_MODEL_H
