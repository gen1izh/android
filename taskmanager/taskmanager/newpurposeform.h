#ifndef NEWPURPOSEFORM_H
#define NEWPURPOSEFORM_H

#include <QWidget>
#include <QDate>


namespace Ui {
class NewPurposeForm;
}

class NewPurposeForm : public QWidget
{
  Q_OBJECT

public:
  explicit NewPurposeForm(QWidget *parent = 0);
  ~NewPurposeForm();

private slots:
  void on_saveButton_clicked();

private:
  Ui::NewPurposeForm *ui;
};

#endif // NEWPURPOSEFORM_H
