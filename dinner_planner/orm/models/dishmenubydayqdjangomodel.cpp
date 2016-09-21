#include "dishmenubydayqdjangomodel.h"

QString DishMenuByDay::day() const
{
    return m_day;
}

void DishMenuByDay::setDay(const QString &day)
{
    m_day = day;
}

QString DishMenuByDay::dishName() const
{
    return m_dishName;
}

void DishMenuByDay::setDishName(const QString &dishName)
{
    m_dishName = dishName;
}

QString DishMenuByDay::lunchTime() const
{
    return m_lunchTime;
}

void DishMenuByDay::setLunchTime(const QString &lunchTime)
{
    m_lunchTime = lunchTime;
}



