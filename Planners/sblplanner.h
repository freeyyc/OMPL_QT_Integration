#ifndef SBLPLANNER_H
#define SBLPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/sbl/SBL.h"
#include "../mapplannerconfiguration.h"
#include "../rangeconfiguration.h"

class SBLPlanner : public PlannerInterface{
public:
    SBLPlanner(){
        m_configurations.addConfiguration(new RangeConfiguration{0.0});
    }

    std::string getName() const override{
        return "SBL";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) override{
        auto planner = std::make_shared<ompl::geometric::SBL>(si);
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


#endif // SBLPLANNER_H
