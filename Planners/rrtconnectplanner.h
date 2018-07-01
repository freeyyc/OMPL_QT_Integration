#ifndef RRTCONNECTPLANNER_H
#define RRTCONNECTPLANNER_H

#include "../plannerinterface.h"
#include "ompl/geometric/planners/rrt/RRTConnect.h"

class RRTConnectPlanner : public PlannerInterface{
public:
    std::string getName() const override{
        return "RRTConnect";
    }
    std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const override{
        return std::make_shared<ompl::geometric::RRTConnect>(si);
    }
};

#endif // RRTCONNECTPLANNER_H
