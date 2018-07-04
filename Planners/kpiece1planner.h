#ifndef KPIECE1PLANNER_H
#define KPIECE1PLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/kpiece/KPIECE1.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"
#include "../goalbiasconfiguration.h"

class KPIECEPlanner : public PlannerInterface{
public:
    KPIECEPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
        m_configurations.addConfiguration(new GoalBiasConfiguration{0.05});
    }
    std::string getName() const override{
        return "KPIECE1";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        auto planner = std::make_shared<ompl::geometric::KPIECE1>(si);
        auto* range_configuration = static_cast<RangeConfiguration*>(m_configurations.getConfiguration(RangeConfiguration().getName()));
        auto* goal_bias_configuration = static_cast<GoalBiasConfiguration*>(m_configurations.getConfiguration(GoalBiasConfiguration().getName()));
        planner->setRange(range_configuration->getRange());
        planner->setGoalBias(goal_bias_configuration->getGoalBias());
        return planner;
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }
    virtual PlannerInterface* copy(){
        auto * copy_planner = new KPIECEPlanner;
        copy_planner->m_configurations = m_configurations;
        return copy_planner;
    }

private:
    MapPlannerConfiguration m_configurations;
};


#endif // KPIECE1PLANNER_H
