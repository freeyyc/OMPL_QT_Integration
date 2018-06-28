#ifndef MAPSTATEVALIDITYCHECKER_H
#define MAPSTATEVALIDITYCHECKER_H

#include <ompl/base/StateValidityChecker.h>
#include "map2d.h"

namespace ob = ompl::base;

class MapStateValidityChecker: public ob::StateValidityChecker{
public:
    MapStateValidityChecker(ob::SpaceInformation* si, const Map2d & map): ob::StateValidityChecker{si}, m_map{map}{}
    MapStateValidityChecker(const ob::SpaceInformationPtr &si, const Map2d & map): ob::StateValidityChecker{si}, m_map{map}{}

    bool isValid(const ob::State *state) const override;
private:
    Map2d m_map;
};

#endif // MAPSTATEVALIDITYCHECKER_H
