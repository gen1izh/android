#ifndef CREATEREPORTFORM_H
#define CREATEREPORTFORM_H

#include <QWidget>

namespace Ui {
class CreateReportForm;
}

class CreateReportForm : public QWidget
{
  Q_OBJECT

public:
  explicit CreateReportForm(QWidget *parent = 0);
  ~CreateReportForm();

private:
  Ui::CreateReportForm *ui;
};

#endif // CREATEREPORTFORM_H
