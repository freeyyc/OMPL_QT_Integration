#ifndef ESTPLANNER_H
#define ESTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/est/EST.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"
#include "../goalbiasconfiguration.h"

class ESTPlanner : public PlannerInterface{
public:
    ESTPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
        m_configurations.addConfiguration(new GoalBiasConfiguration{0.5});
    }
    std::string getName() const override{
        return "EST";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        return std::make_shared<ompl::geometric::EST>(si);
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }

private:
    MapPlannerConfiguration m_configurations;
};


#endif // ESTPLANNER_H
