#include "taskqdjangomodel.h"

QString Task::name() const
{
    return m_name;
}

void Task::setName(const QString &name)
{
    m_name = name;
}

QString Task::description() const
{
    return m_description;
}

void Task::setDescription(const QString &description)
{
    m_description = description;
}

QString Task::date() const
{
    return m_date;
}

void Task::setDate(const QString &date)
{
    m_date = date;
}

QString Task::status() const
{
    return m_status;
}

void Task::setStatus(const QString &status)
{
    m_status = status;
}

QString Task::results() const
{
    return m_results;
}

void Task::setResults(const QString &results)
{
    m_results = results;
}
