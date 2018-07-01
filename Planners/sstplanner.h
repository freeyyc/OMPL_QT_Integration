#ifndef SSTPLANNER_H
#define SSTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/sst/SST.h"

class SSTPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "SST";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::SST>(si);
    }
};

#endif // SSTPLANNER_H
