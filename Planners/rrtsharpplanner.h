#ifndef RRTSHARPPLANNER_H
#define RRTSHARPPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/rrt/RRTsharp.h"

class RRTSharpPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "RRTsharp";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::RRTsharp>(si);
    }
};

#endif // RRTSHARPPLANNER_H
