#ifndef PLANNERINTERFACE_H
#define PLANNERINTERFACE_H
#include <string>
#include <ompl/base/Planner.h>


class PlannerInterface{
public:
    virtual const std::string & getName() const = 0;
    virtual std::shared_ptr<ompl::base::Planner> getPlanner(std::shared_ptr<ompl::base::SpaceInformation> si) const = 0;
private:
};

#endif // PLANNERINTERFACE_H
