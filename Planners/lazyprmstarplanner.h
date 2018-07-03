#ifndef LAZYPRMSTARPLANNER_H
#define LAZYPRMSTARPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/prm/LazyPRMstar.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"

class LazyPRMStarPlanner : public PlannerInterface{
public:
    LazyPRMStarPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
    }
    std::string getName() const override{
        return "LazyPRMstar";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        return std::make_shared<ompl::geometric::LazyPRMstar>(si);
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }

private:
    MapPlannerConfiguration m_configurations;
};


#endif // LAZYPRMSTARPLANNER_H
