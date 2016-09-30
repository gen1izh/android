#ifndef COMMON_SHARED_SINGLETON_H
#define COMMON_SHARED_SINGLETON_H

#include <QObject>
#include <QScopedPointer>

#include "addnewtaskform.h"
#include "createreportform.h"
#include "listalltasksform.h"
#include "newpurposeform.h"
#include "mainwindow.h"
#include "newpostform.h"
#include "settingsform.h"
#include "taskmanagerform.h"

#include <orm/models/purposemodel.h>
#include <orm/models/taskmodel.h>
#include <orm/models/postmodel.h>

class CommonSharedSingleton : public QObject
{
    Q_OBJECT

    CommonSharedSingleton(QObject *parent = 0);
    CommonSharedSingleton(const CommonSharedSingleton &);
    CommonSharedSingleton &operator=(const CommonSharedSingleton &);

    int m_id;

    QScopedPointer<PurposeModel> m_purposeModel;
    QScopedPointer<TaskModel> m_taskModel;
    QScopedPointer<PostModel> m_postModel;

public:

    static CommonSharedSingleton &instance(){
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


    void setCurrentTaskId(int id);

    PurposeModel * getPurposeModel() const;

    TaskModel * getTaskModel() const;

    PostModel * getPostModel() const;

signals:

public slots:
};

#endif // COMMON_SHARED_SINGLETON_H
