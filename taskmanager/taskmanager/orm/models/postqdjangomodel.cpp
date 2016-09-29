#include "postqdjangomodel.h"


QString Post::post() const
{
    return m_post;
}

void Post::setPost(const QString &post)
{
    m_post = post;
}

QString Post::date() const
{
    return m_date;
}

void Post::setDate(const QString &date)
{
    m_date = date;
}
