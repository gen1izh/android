#ifndef PURPOSE_QDJANGO_MODEL_H
#define PURPOSE_QDJANGO_MODEL_H

#include "../db/QDjangoModel.h"

class Purpose : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString monthYear READ monthYear WRITE setMonthYear)
    Q_PROPERTY(QString purpose READ purpose WRITE setPurpose)

    Q_CLASSINFO("monthYear", "max_length=50")
    Q_CLASSINFO("purpose", "max_length=1024")

public:

    QString monthYear() const;
    void setMonthYear(const QString &monthYear);

    QString purpose() const;
    void setPurpose(const QString &purpose);

private:
    QString   m_monthYear;
    QString   m_purpose;
};

#endif // PURPOSE_QDJANGO_MODEL_H
