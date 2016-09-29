#ifndef NEWPOSTFORM_H
#define NEWPOSTFORM_H

#include <QWidget>

namespace Ui {
class NewPostForm;
}

class NewPostForm : public QWidget
{
  Q_OBJECT

public:
  explicit NewPostForm(QWidget *parent = 0);
  ~NewPostForm();

private:
  Ui::NewPostForm *ui;
};

#endif // NEWPOSTFORM_H
