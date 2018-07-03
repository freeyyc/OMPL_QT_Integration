#ifndef LAZYPRMPLANNER_H
#define LAZYPRMPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/prm/LazyPRM.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"

class LazyPRMPlanner : public PlannerInterface{
public:
    LazyPRMPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
    }
    std::string getName() const override{
        return "LazyPRM";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        auto planner = std::make_shared<ompl::geometric::LazyPRM>(si);
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


#endif // LAZYPRMPLANNER_H
