#ifndef MENUVARIABLES_H
#define MENUVARIABLES_H
#include "pointviewer.h"

class MenuVariables{
public:
    MenuVariables(){}

    MenuVariables(PointViewer start_point, PointViewer goal_point):m_start_point{start_point},m_goal_point{goal_point}{}

    PointViewer & startPoint(){return m_start_point;}
    PointViewer & goalPoint(){return m_goal_point;}

private:
    PointViewer m_start_point;
    PointViewer m_goal_point;
};

#endif // MENUVARIABLES_H
