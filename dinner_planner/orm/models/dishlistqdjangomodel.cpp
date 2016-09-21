#include "dishlistqdjangomodel.h"

QString DishList::name() const
{
    return m_name;
}

void DishList::setName(const QString &name)
{
    m_name = name;
}

QString DishList::description() const
{
    return m_description;
}

void DishList::setDescription(const QString &description)
{
    m_description = description;
}



