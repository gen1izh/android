#ifndef GLOBALS_VARIABLES
#define GLOBALS_VARIABLES

#include "orm/models/dishslistmodel.h"
#include "orm/models/dishsbydaymodel.h"

#include "lunchtimeslist.h"
#include "newdishform.h"
#include "dishslistform.h"
#include "dishsbytimeform.h"
#include "farplannerform.h"

#include "mainwindow.h"

class GlobalVariables
{
public:
    static GlobalVariables& Instance()
    {
        static GlobalVariables theSingleInstance;
        return theSingleInstance;
    }

    DishListModel *dishListModel() const;
    void setDishListModel(DishListModel *dishListModel);

    DishsByDayModel *dishsByDayModel() const;
    void setDishsByDayModel(DishsByDayModel *dishsByDayModel);

    void InitializeForms();

    void setMainWindowPointer(MainWindow *ptr);

    LunchTimesList *lunchTimesList() const;
    NewDishForm *newDishForm() const;
    DishsListForm *dishsListForm() const;
    DishsByTimeForm *dishsByTimeForm() const;
    MainWindow *mainWindow() const;

    FarPlannerForm *farPlannerForm() const;

private:
    GlobalVariables(){}
    GlobalVariables(const GlobalVariables& root);
    GlobalVariables& operator=(const GlobalVariables&);

    /*!
     * \brief
     */
    DishListModel       *m_dishListModel;

    /*!
     * \brief
     */
    DishsByDayModel     *m_dishsByDayModel;

    /*!
     * \brief
     */
    QScopedPointer<LunchTimesList>  m_lunchTimesList;

    /*!
     * \brief
     */
    QScopedPointer<NewDishForm>     m_newDishForm;

    /*!
     * \brief
     */
    QScopedPointer<DishsListForm>   m_dishsListForm;

    /*!
     * \brief
     */
    QScopedPointer<DishsByTimeForm> m_dishsByTimeForm;


    /*!
     * \brief
     */
    QScopedPointer<FarPlannerForm> m_farPlannerForm;

    /*!
     * \brief
     */
    MainWindow      *m_mainWindow;

};



#endif // GLOBALS_VARIABLES



