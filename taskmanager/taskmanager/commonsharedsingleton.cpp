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


    m_purposeModel.reset(new PurposeModel());
    m_taskModel.reset(new TaskModel());
    m_postModel.reset(new PostModel());


}

PostModel *CommonSharedSingleton::getPostModel() const
{
    return m_postModel.data();
}

TaskModel *CommonSharedSingleton::getTaskModel() const
{
    return m_taskModel.data();
}

PurposeModel *CommonSharedSingleton::getPurposeModel() const
{
    return m_purposeModel.data();
}

MainWindow *CommonSharedSingleton::getMainWindow() const
{
    return mainWindow;
}

void CommonSharedSingleton::setMainWindow(MainWindow *value)
{
    mainWindow = value;
}

void CommonSharedSingleton::setCurrentTaskId(int id)
{
    m_id = id;
}
