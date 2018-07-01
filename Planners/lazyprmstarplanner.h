#ifndef LAZYPRMSTARPLANNER_H
#define LAZYPRMSTARPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/prm/LazyPRMstar.h"

class LazyPRMStarPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "LazyPRMstar";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::LazyPRMstar>(si);
    }
};


#endif // LAZYPRMSTARPLANNER_H
