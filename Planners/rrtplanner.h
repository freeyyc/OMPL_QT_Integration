#ifndef RRTPLANNER_H
#define RRTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/rrt/RRT.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"
#include "../goalbiasconfiguration.h"

class RRTPlanner : public PlannerInterface{
public:
    RRTPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
        m_configurations.addConfiguration(new GoalBiasConfiguration{0.05});
    }
    std::string getName() const override{
        return "RRT";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        return std::make_shared<ompl::geometric::RRT>(si);
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }

private:
    MapPlannerConfiguration m_configurations;
};

#endif // RRTPLANNER_H
