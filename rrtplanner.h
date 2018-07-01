#ifndef RRTPLANNER_H
#define RRTPLANNER_H

#include "plannerinterface.h"
#include "ompl/geometric/planners/rrt/RRT.h"

class RRTPlanner : public PlannerInterface{
public:
    const std::string & getName() const override{
        return "RRT";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::RRT>(si);
    }
};

#endif // RRTPLANNER_H
