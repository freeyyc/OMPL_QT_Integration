#ifndef LAZYRRTPLANNER_H
#define LAZYRRTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/rrt/LazyRRT.h"

class LazyRRTPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "LazyRRT";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::LazyRRT>(si);
    }
};

#endif // LAZYRRTPLANNER_H
