#ifndef ESTPLANNER_H
#define ESTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/est/EST.h"

class ESTPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "EST";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::EST>(si);
    }
};


#endif // ESTPLANNER_H
