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






