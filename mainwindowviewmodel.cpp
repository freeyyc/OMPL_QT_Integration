#include "mainwindowviewmodel.h"
#include "mapstatevaliditychecker.h"

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
    if(m_planners.count(name)){
        return m_planners[name];
    }
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
        m_start_point = env->getStartPoint();
        m_goal_point = env->getGoalPoint();
    }
}

void MainWindowViewModel::plan(PlannerInterface * planner_interface, EnvInterface * environment_interface){
    // construct the state space we are planning in
    auto space(std::make_shared<ob::RealVectorStateSpace>(2));

    // set the bounds for the R^3 part of SE(3)
    ob::RealVectorBounds bounds(2);
    bounds.setLow(-100);
    bounds.setHigh(100);

    space->setBounds(bounds);

    // construct an instance of  space information from this state space
    auto si(std::make_shared<ob::SpaceInformation>(space));

    auto map = environment_interface->getMap();

    auto map_state_checker(std::make_shared<MapStateValidityChecker>(si,map));

    // set state validity checking for this space
//     si->setStateValidityChecker(isStateValid);
    si->setStateValidityChecker(map_state_checker);

    // create a random start state
    ob::ScopedState<ob::RealVectorStateSpace> start(space);
    start->values[0] = -70;
    start->values[1] = 30;


    // create a random goal state
    ob::ScopedState<ob::RealVectorStateSpace> goal(space);
    goal->values[0] = 80;
    goal->values[1] = -30;

    // create a problem instance
    auto pdef(std::make_shared<ob::ProblemDefinition>(si));

     // set the start and goal states
     pdef->setStartAndGoalStates(start, goal);

     // create a planner for the defined space
     auto planner(planner_interface->getPlanner(si));

    //planner->setRange(1);

     // set the problem we are trying to solve for the planner
     planner->setProblemDefinition(pdef);

     // perform setup steps for the planner
     planner->setup();


     // print the settings for this space
     si->printSettings(std::cout);

     // print the problem settings
     pdef->print(std::cout);

     // attempt to solve the problem within one second of planning time
     ob::PlannerStatus solved = planner->ob::Planner::solve(1.0);

     ob::PlannerData planner_data{si};
     planner->getPlannerData(planner_data);

     if (solved)
     {
         std::cout << "Numero de vertices: " << planner_data.numVertices() << std::endl;
         std::cout << "Numero de cantos: " << planner_data.numEdges() << std::endl;

         // get the goal representation from the problem definition (not the same as the goal state)
         // and inquire about the found path
         auto path = pdef->getSolutionPath()->as<og::PathGeometric>();

         std::cout << "Found solution:" << std::endl;
         m_custom_drawer.drawSearchGraph(planner_data);
         m_custom_drawer.drawGeometricPath(path);
     }
     else
         std::cout << "No solution found" << std::endl;
}
