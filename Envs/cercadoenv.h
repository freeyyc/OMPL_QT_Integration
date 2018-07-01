#ifndef CERCADOENV_H
#define CERCADOENV_H

#include "../envinterface.h"

class CercadoEnv : public EnvInterface{
public:
    std::string getName() const override{
        return "Cercado";
    }
    Map2d getMap() const override{
        Map2d map{100,100};

        map.insertObstacle(Obstacle{{-50, 20},{-30,50}});
        map.insertObstacle(Obstacle{{-50, 50},{50, 70}});
        map.insertObstacle(Obstacle{{30,-50},{50, 70}});
        map.insertObstacle(Obstacle{{-50, -70},{50,-50}});
        map.insertObstacle(Obstacle{{-50,-50},{-30,20}});

        return map;
    }
};

#endif // CERCADOENV_H
