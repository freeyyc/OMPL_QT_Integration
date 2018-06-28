#include "mapstatevaliditychecker.h"

bool MapStateValidityChecker::isValid(const ob::State *state) const{
    const auto *pos = state->as<ob::RealVectorStateSpace::StateType>();

    return !m_map.checkColision(Point{pos});
}
