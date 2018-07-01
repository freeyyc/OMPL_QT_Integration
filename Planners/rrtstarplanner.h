#ifndef RRTSTARPLANNER_H
#define RRTSTARPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/rrt/RRTstar.h"

class RRTStarPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "RRTstar";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::RRTstar>(si);
    }
};

#endif // RRTSTARPLANNER_H
