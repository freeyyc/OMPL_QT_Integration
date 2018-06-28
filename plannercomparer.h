#ifndef PLANNERCOMPARER_H
#define PLANNERCOMPARER_H

#include "customdrawer.h"

class PlannerComparer{
public:
    PlannerComparer(QCustomPlot * custom_plot): m_custom_plot{custom_plot}, m_drawer{custom_plot}{}

    bool buildMap();
private:
    QCustomPlot m_custom_plot;
    CustomDrawer m_drawer;
};

#endif // PLANNERCOMPARER_H
