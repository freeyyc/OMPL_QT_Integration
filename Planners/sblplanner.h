#ifndef SBLPLANNER_H
#define SBLPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/sbl/SBL.h"

class SBLPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "SBL";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::SBL>(si);
    }
};


#endif // SBLPLANNER_H
