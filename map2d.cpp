#include "map2d.h"

bool Map2d::checkColision(const Point & p) const{
    for(const auto & obstacle:m_obstacles){
        if(obstacle.isCollision(p)) return true;
    }
    return false;
}
