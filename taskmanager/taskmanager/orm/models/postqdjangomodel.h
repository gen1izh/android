#ifndef POST_QDJANGO_MODEL_H
#define POST_QDJANGO_MODEL_H

#include "../db/QDjangoModel.h"

class Post : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date WRITE setDate)
    Q_PROPERTY(QString post READ post WRITE setPost)

    Q_CLASSINFO("date", "max_length=50")
    Q_CLASSINFO("post", "max_length=1024")

public:


    QString post() const;
    void setPost(const QString &post);

    QString date() const;
    void setDate(const QString &date);

private:
    QString   m_date;
    QString   m_post;
};

#endif // POST_QDJANGO_MODEL_H
