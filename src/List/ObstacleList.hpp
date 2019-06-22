#pragma once

#include <list>
#include "../Obstacles/Obstacle.hpp"

class ObstaclesList {
    public:
        std::list<Obstacles::Obstacle*> obstacles;

        void add(Obstacles::Obstacle* _el){
            obstacles.push_back(_el);
        }
        void remove(Obstacles::Obstacle* _el){
            obstacles.remove(_el);
        }
        void clear(){
            std::list<Obstacles::Obstacle*>::iterator itr;
            for(itr = begin(); itr != end(); ++itr){
                delete *itr;
            }
            obstacles.clear();
        }

        const std::list<Obstacles::Obstacle*>::iterator begin(){ return obstacles.begin(); }
        const std::list<Obstacles::Obstacle*>::iterator end(){ return obstacles.end(); }
};