#ifndef PLANNERINTERFACE_H
#define PLANNERINTERFACE_H
#include <string>
#include <ompl/base/Planner.h>
#include "plannerconfigurationinterface.h"

class PlannerInterface{
public:
    virtual std::string getName() const = 0;
    virtual std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) = 0;
    virtual PlannerConfigurationInterface* getConfigurations() = 0;
};

#endif // PLANNERINTERFACE_H
