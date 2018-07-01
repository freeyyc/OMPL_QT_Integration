#ifndef DENSOENV_H
#define DENSOENV_H

#include "../envinterface.h"

class DensoEnv : public EnvInterface{
public:
    std::string getName() const override{
        return "Denso";
    }
    Map2d getMap() const override{
        Map2d map{100,100};

        map.insertObstacle(Obstacle{{-90,70},{-70, 90}});
        map.insertObstacle(Obstacle{{-30, 60},{-10,80}});
        map.insertObstacle(Obstacle{{10, 80},{30, 90}});
        map.insertObstacle(Obstacle{{70, 70},{90, 90}});
        map.insertObstacle(Obstacle{{-70, 30},{-50,50}});
        map.insertObstacle(Obstacle{{-40, 20},{-30, 30}});
        map.insertObstacle(Obstacle{{-10, 10},{10, 30}});
        map.insertObstacle(Obstacle{{10, 40},{30, 60}});
        map.insertObstacle(Obstacle{{40, 50},{60, 60}});
        map.insertObstacle(Obstacle{{30, 0},{50, 20}});
        map.insertObstacle(Obstacle{{80, 10},{100, 30}});
        map.insertObstacle(Obstacle{{-20, -60},{20,-20}});
        map.insertObstacle(Obstacle{{-90, -30},{-70, -10}});
        map.insertObstacle(Obstacle{{-50, -30},{-30, -10}});
        map.insertObstacle(Obstacle{{-60,-70},{-40,-50}});
        map.insertObstacle(Obstacle{{-10,-100},{10,-80}});
        map.insertObstacle(Obstacle{{30, -90},{50,-70}});
        map.insertObstacle(Obstacle{{50,-40},{70,-20}});
        map.insertObstacle(Obstacle{{80, -40},{90, -20}});
        map.insertObstacle(Obstacle{{70,-80},{90,-60}});

        return map;
    }
};

#endif // DENSOENV_H
