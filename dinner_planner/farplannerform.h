#ifndef FARPLANNERFORM_H
#define FARPLANNERFORM_H

#include <QWidget>

namespace Ui {
class FarPlannerForm;
}

class FarPlannerForm : public QWidget
{
    Q_OBJECT

public:
    explicit FarPlannerForm(QWidget *parent = 0);
    ~FarPlannerForm();

private slots:
  void on_chooseDateButton_clicked();

private:
    Ui::FarPlannerForm *ui;
};

#endif // FARPLANNERFORM_H
