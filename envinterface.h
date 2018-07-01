#ifndef ENVINTERFACE_H
#define ENVINTERFACE_H

#include <string>
#include "map2d.h"


class EnvInterface{
public:
    virtual const std::string & getName() const = 0;
    virtual Map2d getMap() const = 0;
private:
};

#endif // ENVINTERFACE_H
