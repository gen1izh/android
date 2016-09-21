#ifndef BASKETFORM_H
#define BASKETFORM_H

#include <QWidget>

namespace Ui {
class BasketForm;
}

class BasketForm : public QWidget
{
  Q_OBJECT

public:
  explicit BasketForm(QWidget *parent = 0);
  ~BasketForm();

private slots:
    void on_toMainButton_clicked();

private:
  Ui::BasketForm *ui;
protected:
    void showEvent(QShowEvent * event);
};

#endif // BASKETFORM_H
