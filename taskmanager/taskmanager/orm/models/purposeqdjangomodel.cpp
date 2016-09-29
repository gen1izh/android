#include "purposeqdjangomodel.h"

QString Purpose::monthYear() const
{
    return m_monthYear;
}

void Purpose::setMonthYear(const QString &monthYear)
{
    m_monthYear = monthYear;
}

QString Purpose::purpose() const
{
    return m_purpose;
}

void Purpose::setPurpose(const QString &purpose)
{
    m_purpose = purpose;
}
