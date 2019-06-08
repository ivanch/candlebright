#include "World.hpp"

void World::update(){
    collisionManager();
    for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->update();
    }
}

void World::drawAll(Engine* engine){
    engine->setView();
    draw(engine);
    for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->draw(engine);
    }
}

void World::draw(Engine* engine){
    engine->draw(*background);
}

void World::gravity(){
    for(auto itr = objects.getFirst(); itr != NULL; itr = itr->getNext()){
        Object* obj1 = itr->getData();
        if(!obj1->isCollidingDown()){
            obj1->fall();
        }
    }
}

void World::collisionManager(){
    for(auto itr1 = objects.getFirst(); itr1 != NULL; itr1 = itr1->getNext()){
        Object* obj1 = itr1->getData();
        obj1->setCollidingUp(false);
        obj1->setCollidingRight(false);
        obj1->setCollidingLeft(false);
        obj1->setCollidingDown(false);
    }
    for(auto itr1 = objects.getFirst(); itr1 != NULL; itr1 = itr1->getNext()){
        Object* obj1 = itr1->getData();
        if(!obj1->isCollisionEnabled()) continue;
        for(auto itr2 = itr1; itr2 != NULL; itr2 = itr2->getNext()){
            Object* obj2 = itr2->getData();
            if(!obj2->isCollisionEnabled()) continue;
            if(obj1 == obj2) continue;
            if(Intersect::intersectsUp(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingUp(true);
                obj2->setCollidingDown(true);
            }else if(Intersect::intersectsDown(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingDown(true);
                obj2->setCollidingUp(true);
            }
            if(Intersect::intersectsRight(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingRight(true);
                obj2->setCollidingLeft(true);
            }else if(Intersect::intersectsLeft(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingLeft(true);
                obj2->setCollidingRight(true);
            }
        }
    }
}
