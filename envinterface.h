#ifndef ENVINTERFACE_H
#define ENVINTERFACE_H

#include <string>
#include "map2d.h"


class EnvInterface{
public:
    virtual std::string getName() const = 0;
    virtual Map2d getMap() const = 0;
    virtual Point getStartPoint() const{
        return {0,0};
    }
    virtual Point getGoalPoint() const{
        return {80,-30};
    }
private:
};

#endif // ENVINTERFACE_H
