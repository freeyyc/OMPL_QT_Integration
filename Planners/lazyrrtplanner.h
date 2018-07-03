#ifndef LAZYRRTPLANNER_H
#define LAZYRRTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/rrt/LazyRRT.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"
#include "../goalbiasconfiguration.h"

class LazyRRTPlanner : public PlannerInterface{
public:
    LazyRRTPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
        m_configurations.addConfiguration(new GoalBiasConfiguration{0.05});
    }
    std::string getName() const override{
        return "LazyRRT";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        return std::make_shared<ompl::geometric::LazyRRT>(si);
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;+
    }

private:
    MapPlannerConfiguration m_configurations;
};

#endif // LAZYRRTPLANNER_H
