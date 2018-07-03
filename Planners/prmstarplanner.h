#ifndef PRMSTARPLANNER_H
#define PRMSTARPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/prm/PRMstar.h"
#include "../mapplannerconfiguration.h"

class PRMStarPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "PRMstar";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        return std::make_shared<ompl::geometric::PRMstar>(si);
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }

private:
    MapPlannerConfiguration m_configurations;
};


#endif // PRMSTARPLANNER_H
