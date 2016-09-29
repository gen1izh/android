#ifndef NEWPURPOSEFORM_H
#define NEWPURPOSEFORM_H

#include <QWidget>

namespace Ui {
class NewPurposeForm;
}

class NewPurposeForm : public QWidget
{
  Q_OBJECT

public:
  explicit NewPurposeForm(QWidget *parent = 0);
  ~NewPurposeForm();

private:
  Ui::NewPurposeForm *ui;
};

#endif // NEWPURPOSEFORM_H
