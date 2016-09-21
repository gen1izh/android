#include "models.h"

DishListModel *GlobalVariables::dishListModel() const
{
    return m_dishListModel;
}

void GlobalVariables::setDishListModel(DishListModel *dishListModel)
{
    m_dishListModel = dishListModel;
}

DishsByDayModel *GlobalVariables::dishsByDayModel() const
{
    return m_dishsByDayModel;
}

void GlobalVariables::setDishsByDayModel(DishsByDayModel *dishsByDayModel)
{
    m_dishsByDayModel = dishsByDayModel;
}

void GlobalVariables::InitializeForms()
{
    m_lunchTimesList.reset(new LunchTimesList());
    m_newDishForm.reset(new NewDishForm());
    m_dishsListForm.reset(new DishsListForm());
    m_dishsByTimeForm.reset(new DishsByTimeForm());
    m_farPlannerForm.reset(new FarPlannerForm());

    m_basketForm.reset(new BasketForm());
    m_versionInfoForm.reset(new VersionInfoForm());
}

void GlobalVariables::resetCurrentDayOnLabels()
{
  lunchTimesList()->setCurrentDay(m_currentDay);
  dishsListForm()->setCurrentDay(m_currentDay);
  dishsByTimeForm()->setCurrentDay(m_currentDay);
}

void GlobalVariables::setMainWindowPointer(MainWindow *ptr)
{
    m_mainWindow = ptr;
}

LunchTimesList *GlobalVariables::lunchTimesList() const
{
    return m_lunchTimesList.data();
}


NewDishForm  *GlobalVariables::newDishForm() const
{
    return m_newDishForm.data();
}


DishsListForm *GlobalVariables::dishsListForm() const
{
    return m_dishsListForm.data();
}


DishsByTimeForm *GlobalVariables::dishsByTimeForm() const
{
    return m_dishsByTimeForm.data();
}


MainWindow *GlobalVariables::mainWindow() const
{
    return m_mainWindow;
}

FarPlannerForm *GlobalVariables::farPlannerForm() const
{
    return m_farPlannerForm.data();
}
QString GlobalVariables::currentDay() const
{
    return m_currentDay;
}

void GlobalVariables::setCurrentDay(const QString &currentDay)
{
    m_currentDay = currentDay;
}
QString GlobalVariables::currentTrapeza() const
{
    return m_currentTrapeza;
}

void GlobalVariables::setCurrentTrapeza(const QString &currentTrapeza)
{
    m_currentTrapeza = currentTrapeza;
}

BasketForm *GlobalVariables::basketForm() const
{
    return m_basketForm.data();
}
VersionInfoForm *GlobalVariables::versionInfoForm() const
{
    return m_versionInfoForm.data();
}










