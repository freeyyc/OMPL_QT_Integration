#include "mainwindowviewmodel.h"

using std::unordered_map;
using std::vector;
using std::string;

void MainWindowViewModel::addEnviroment(EnvInterface* interface){
    if(interface){
        m_environments.insert(std::make_pair(interface->getName(),interface));
    }
}
void MainWindowViewModel::addPlanner(PlannerInterface* interface){
    if(interface){
        m_planners.insert(std::make_pair(interface->getName(),interface));
    }
}

vector<string> MainWindowViewModel::getEnvironmentNames(){
    vector<string> names;
    for(auto & kv: m_environments){
        names.push_back(kv.first);
    }
    return names;
}

vector<string> MainWindowViewModel::getPlannerNames(){
    vector<string> names;
    for(auto & kv: m_planners){
        names.push_back(kv.first);
    }
    return names;
}

PlannerInterface* MainWindowViewModel::getPlanner(string name){
    return nullptr;
}

EnvInterface* MainWindowViewModel::getEnvironment(string name){
    if(m_environments.count(name)){
        return m_environments[name];
    }
    return nullptr;
}

void MainWindowViewModel::environmentChanged(std::string name){
    if(auto * env = getEnvironment(name)){
        m_custom_drawer.drawMap2d(env->getMap());
        m_custom_plot->xAxis->setRange(-100, 100);
        m_custom_plot->yAxis->setRange(-100, 100);
        m_custom_plot->replot();
    }
}
