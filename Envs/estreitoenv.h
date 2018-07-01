#ifndef ESTREITOENV_H
#define ESTREITOENV_H

#include "../envinterface.h"

class EstreitoEnv : public EnvInterface{
public:
    std::string getName() const override{
        return "Estreito";
    }
    Map2d getMap() const override{
        Map2d map{100,100};

        map.insertObstacle(Obstacle{{-30,-100},{30,-10}});
        map.insertObstacle(Obstacle{{-30, 10},{30,100}});
        return map;
    }
};

#endif // ESTREITOENV_H
