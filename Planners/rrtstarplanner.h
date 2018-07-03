#ifndef RRTSTARPLANNER_H
#define RRTSTARPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/rrt/RRTstar.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"
#include "../goalbiasconfiguration.h"

class RRTStarPlanner : public PlannerInterface{
public:
    RRTStarPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
        m_configurations.addConfiguration(new GoalBiasConfiguration{0.05});
    }
    std::string getName() const override{
        return "RRTstar";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        auto planner = std::make_shared<ompl::geometric::RRTstar>(si);
        auto* range_configuration = static_cast<RangeConfiguration*>(m_configurations.getConfiguration(RangeConfiguration().getName()));
        auto* goal_bias_configuration = static_cast<GoalBiasConfiguration*>(m_configurations.getConfiguration(GoalBiasConfiguration().getName()));
        planner->setRange(range_configuration->getRange());
        planner->setGoalBias(goal_bias_configuration->getGoalBias());
        return planner;
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }

private:
    MapPlannerConfiguration m_configurations;
};

#endif // RRTSTARPLANNER_H
