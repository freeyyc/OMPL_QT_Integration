#ifndef RRTCONNECTPLANNER_H
#define RRTCONNECTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/rrt/RRTConnect.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"

class RRTConnectPlanner : public PlannerInterface{
public:
    RRTConnectPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
    }
    std::string getName() const override{
        return "RRTConnect";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        auto planner = std::make_shared<ompl::geometric::RRTConnect>(si);
        auto* range_configuration = static_cast<RangeConfiguration*>(m_configurations.getConfiguration(RangeConfiguration().getName()));
        planner->setRange(range_configuration->getRange());
        return planner;
    }
    PlannerConfigurationInterface* getConfigurations(){
        return &m_configurations;
    }

private:
    MapPlannerConfiguration m_configurations;
};

#endif // RRTCONNECTPLANNER_H
