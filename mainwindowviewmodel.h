#ifndef MAINWINDOWVIEWMODEL_H
#define MAINWINDOWVIEWMODEL_H
#include <vector>
#include <string>
#include <unordered_map>

#include "plannerinterface.h"
#include "envinterface.h"
#include "customdrawer.h"


class MainWindowViewModel{
public:
    MainWindowViewModel(QCustomPlot* custom_plot):m_custom_drawer{custom_plot},m_custom_plot{custom_plot}{}

    void addEnviroment(EnvInterface* interface);
    void addPlanner(PlannerInterface* interface);

    std::vector<std::string> getEnvironmentNames();
    std::vector<std::string> getPlannerNames();

    PlannerInterface* getPlanner(std::string name);
    EnvInterface* getEnvironment(std::string name);

    void environmentChanged(std::string name);

private:
    CustomDrawer m_custom_drawer;
    QCustomPlot* m_custom_plot;
    std::unordered_map<std::string,EnvInterface*> m_environments;
    std::unordered_map<std::string,PlannerInterface*> m_planners;
};

#endif // MAINWINDOWVIEWMODEL_H
