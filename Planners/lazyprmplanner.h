#ifndef LAZYPRMPLANNER_H
#define LAZYPRMPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/prm/LazyPRM.h"

class LazyPRMPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "LazyPRM";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::LazyPRM>(si);
    }
};


#endif // LAZYPRMPLANNER_H
