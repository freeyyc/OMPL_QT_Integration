#ifndef POINT_H
#define POINT_H

#include "ompl/base/spaces/RealVectorStateSpace.h"
#include "ompl/base/PlannerData.h"

namespace ob = ompl::base;

struct Point{
    Point(double x, double y): x(x), y(y){}
    explicit Point(ob::PlannerDataVertex& vertex){
        auto * state = vertex.getState()->as<ob::RealVectorStateSpace::StateType>();
        x = state->values[0];
        y = state->values[1];
    }

    explicit Point(const ob::RealVectorStateSpace::StateType * state){
        x = state->values[0];
        y = state->values[1];
    }

    double x;
    double y;
};

#endif // POINT_H
