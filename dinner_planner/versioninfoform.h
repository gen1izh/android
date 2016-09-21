#ifndef VERSIONINFOFORM_H
#define VERSIONINFOFORM_H

#include <QWidget>

namespace Ui {
class VersionInfoForm;
}

class VersionInfoForm : public QWidget
{
  Q_OBJECT

public:
  explicit VersionInfoForm(QWidget *parent = 0);
  ~VersionInfoForm();

private slots:
    void on_toMainButton_clicked();

private:
  Ui::VersionInfoForm *ui;
};

#endif // VERSIONINFOFORM_H
