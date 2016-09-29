#ifndef TASK_QDJANGO_MODEL_H
#define TASK_QDJANGO_MODEL_H

#include "../db/QDjangoModel.h"

class Task : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QString date READ date WRITE setDate)
    Q_PROPERTY(QString status READ status WRITE setStatus)
    Q_PROPERTY(QString results READ results WRITE setResults)

    Q_CLASSINFO("name", "max_length=50")
    Q_CLASSINFO("description", "max_length=1024")
    Q_CLASSINFO("date", "max_length=50")
    Q_CLASSINFO("status", "max_length=50")
    Q_CLASSINFO("results", "max_length=1024")

public:

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    QString date() const;
    void setDate(const QString &date);

    QString status() const;
    void setStatus(const QString &status);

    QString results() const;
    void setResults(const QString &results);

private:
    QString   m_name;
    QString   m_description;
    QString   m_date;
    QString   m_status;
    QString   m_results;
};

#endif // TASK_QDJANGO_MODEL_H
