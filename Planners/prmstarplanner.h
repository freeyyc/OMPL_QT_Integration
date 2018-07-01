#ifndef PRMSTARPLANNER_H
#define PRMSTARPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/prm/PRMstar.h"

class PRMStarPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "PRMstar";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::PRMstar>(si);
    }
};


#endif // PRMSTARPLANNER_H
