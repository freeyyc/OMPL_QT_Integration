#include "obstacle.h"

bool Obstacle::isCollision(Point p) const{
    return (m_lower_left_corner.x <= p.x && p.x <= m_top_right_corner.x && m_lower_left_corner.y <= p.y && p.y <= m_top_right_corner.y);
}
