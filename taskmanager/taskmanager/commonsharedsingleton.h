#ifndef COMMON_SHARED_SINGLETON_H
#define COMMON_SHARED_SINGLETON_H

#include <QObject>

#include "addnewtaskform.h"
#include "createreportform.h"
#include "listalltasksform.h"
#include "newpurposeform.h"
#include "mainwindow.h"
#include "newpostform.h"
#include "settingsform.h"
#include "taskmanagerform.h"

class CommonSharedSingleton : public QObject
{
    Q_OBJECT

    CommonSharedSingleton(QObject *parent = 0);
    CommonSharedSingleton(const CommonSharedSingleton &);
    CommonSharedSingleton &operator=(const CommonSharedSingleton &);

public:

    static const CommonSharedSingleton &instance(){
        static CommonSharedSingleton theSingleton;
        return theSingleton;
    }

    AddNewTaskForm     *addNewTaskForm;
    CreateReportForm   *createReportForm;
    ListAllTasksForm   *listAllTasksForm;
    NewPurposeForm     *newPurposeForm;
    MainWindow         *mainWindow;
    NewPostForm        *newPostForm;
    SettingsForm       *settingsForm;
    TaskManagerForm    *taskManagerForm;

    MainWindow *getMainWindow() const;
    void setMainWindow(MainWindow *value);

signals:

public slots:
};

#endif // COMMON_SHARED_SINGLETON_H
