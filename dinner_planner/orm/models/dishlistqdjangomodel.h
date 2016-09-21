#ifndef DISH_LIST_QDJANGO_MODEL_H
#define DISH_LIST_QDJANGO_MODEL_H

#include "../db/QDjangoModel.h"

class DishList : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)

    Q_CLASSINFO("name", "max_length=50")
    Q_CLASSINFO("description", "max_length=2048")

public:
    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

private:
    QString m_name;
    QString m_description;
};

#endif // DISH_LIST_QDJANGO_MODEL_H
