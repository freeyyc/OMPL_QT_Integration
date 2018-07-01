#ifndef KPIECE1PLANNER_H
#define KPIECE1PLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/kpiece/KPIECE1.h"

class KPIECEPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "KPIECE1";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::KPIECE1>(si);
    }
};


#endif // KPIECE1PLANNER_H
