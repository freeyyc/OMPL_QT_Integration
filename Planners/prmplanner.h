#ifndef PRMPLANNER_H
#define PRMPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/prm/PRM.h"
#include "../mapplannerconfiguration.h"

class PRMPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "PRM";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        return std::make_shared<ompl::geometric::PRM>(si);
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }
    virtual PlannerInterface* copy(){
        auto * copy_planner = new PRMPlanner;
        copy_planner->m_configurations = m_configurations;
        return copy_planner;
    }

private:
    MapPlannerConfiguration m_configurations;
};

#endif // PRMPLANNER_H
