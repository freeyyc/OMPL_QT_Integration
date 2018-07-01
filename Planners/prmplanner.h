#ifndef PRMPLANNER_H
#define PRMPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/prm/PRM.h"

class PRMPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "PRM";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::PRM>(si);
    }
};

#endif // PRMPLANNER_H
