#ifndef SSTPLANNER_H
#define SSTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/sst/SST.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"
#include "../goalbiasconfiguration.h"

class SSTPlanner : public PlannerInterface{
public:
    SSTPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{5.0});
        m_configurations.addConfiguration(new GoalBiasConfiguration{0.05});
    }

    std::string getName() const override{
        return "SST";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        auto planner = std::make_shared<ompl::geometric::SST>(si);
        auto* range_configuration = static_cast<RangeConfiguration*>(m_configurations.getConfiguration(RangeConfiguration().getName()));
        auto* goal_bias_configuration = static_cast<GoalBiasConfiguration*>(m_configurations.getConfiguration(GoalBiasConfiguration().getName()));
        planner->setRange(range_configuration->getRange());
        planner->setGoalBias(goal_bias_configuration->getGoalBias());
        return planner;
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }

    PlannerInterface* copy() override{
        auto * copy_planner = new SSTPlanner;
        copy_planner->m_configurations = m_configurations;
        return copy_planner;
    }

private:
    MapPlannerConfiguration m_configurations;
};

#endif // SSTPLANNER_H
