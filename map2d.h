#ifndef MAP2D_H
#define MAP2D_H

#include<vector>
#include "obstacle.h"

class Map2d{
public:
    Map2d(unsigned width, unsigned height):m_width{width},m_height{height}{}

    void insertObstacle(const Obstacle & obstacle){m_obstacles.push_back(obstacle);}
    unsigned numObstacles() const{return m_obstacles.size();}
    const Obstacle & getObstacle(unsigned i) const{return m_obstacles[i];}
    bool checkColision(const Point & p) const;
    unsigned getWidth(){return m_width;}
    unsigned getHeight(){return m_height;}
private:
    unsigned m_width;
    unsigned m_height;
    std::vector<Obstacle> m_obstacles;
};

#endif // MAP2D_H
