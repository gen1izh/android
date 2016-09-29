#include "commonsharedsingleton.h"

CommonSharedSingleton::CommonSharedSingleton(QObject *parent) : QObject(parent)
{
    addNewTaskForm      = new AddNewTaskForm();
    createReportForm    = new CreateReportForm();
    listAllTasksForm    = new ListAllTasksForm();
    newPurposeForm      = new NewPurposeForm();
    mainWindow          = new MainWindow();
    newPostForm         = new NewPostForm();
    settingsForm        = new SettingsForm();
    taskManagerForm     = new TaskManagerForm();
}

MainWindow *CommonSharedSingleton::getMainWindow() const
{
    return mainWindow;
}

void CommonSharedSingleton::setMainWindow(MainWindow *value)
{
    mainWindow = value;
}
