#ifndef TREKS_QDJANGO_MODEL_H
#define TREKS_QDJANGO_MODEL_H

#include "../db/QDjangoModel.h"

class Treks : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)

    Q_CLASSINFO("name", "max_length=50")

public:
    QString name() const;
    void setName(const QString &name);

private:
    QString m_name;
};

#endif // TREKS_QDJANGO_MODEL_H
