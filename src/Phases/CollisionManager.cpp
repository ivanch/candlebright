#include "CollisionManager.hpp"

void CollisionManager::checkCollisions(ThingsList* things){
    for(auto itr = things->begin(); itr != things->end(); ++itr){
        Thing* obj1 = *itr;
        obj1->setCollidingUp(false);
        obj1->setCollidingRight(false);
        obj1->setCollidingLeft(false);
        obj1->setCollidingDown(false);
    }
    for(auto itr1 = things->begin(); itr1 != things->end(); ++itr1){
        Thing* obj1 = *itr1;
        for(auto itr2 = itr1; itr2 != things->end(); ++itr2){
            Thing* obj2 = *itr2;
            if(obj1 == obj2) continue;
            if(intersectsUp(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingUp(true);
                obj2->setCollidingDown(true);
            }else if(intersectsDown(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingDown(true);
                obj2->setCollidingUp(true);
            }
            if(intersectsRight(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingRight(true);
                obj2->setCollidingLeft(true);
            }else if(intersectsLeft(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingLeft(true);
                obj2->setCollidingRight(true);
            }
        }
    }
}