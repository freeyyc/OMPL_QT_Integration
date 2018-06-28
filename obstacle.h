#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "point.h"

class Obstacle
{
public:
    Obstacle(Point lower_left_corner, Point top_right_corner): m_lower_left_corner{lower_left_corner}, m_top_right_corner{top_right_corner}{}

    bool isCollision(Point p) const;
    Point getLowerLeftCorner() const{return m_lower_left_corner;}
    Point getTopRightCorner() const{return m_top_right_corner;}
private:
    Point m_lower_left_corner;
    Point m_top_right_corner;
};

#endif // OBSTACLE_H
