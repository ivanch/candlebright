#include "World.hpp"
#include "utils.hpp"

void World::update(){
    collisionManager();
    for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->update();
    }
    for(auto itr = characters.begin(); itr != characters.end(); ++itr){
        if((*itr)->isAttacking()){
            for(auto itr2 = characters.begin(); itr2 != characters.end(); ++itr2){
                if(itr == itr2) continue; // auto-dano
                cout << getDistance((*itr)->getPos(), (*itr2)->getPos()) << endl;
                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) < 75.0) continue; // Range

                //if((*itr2)->getHealth()-(*itr)->getDamage() <= 0){
                    entities.remove(*itr2);
                    things.remove(*itr2);
                    characters.remove(*itr2);
                //}
                //(*itr2)->takeDamage(*itr, (*itr)->getDamage());
            }
            (*itr)->setAttacking(false);
        }
    }
}

void World::drawAll(Engine* engine){
    draw(engine);
    for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->draw(engine);
    }
}

void World::draw(Engine* engine){
    engine->draw(*background);
}

void World::gravity(){
    for(auto itr = things.begin(); itr != things.end(); ++itr){
        Thing* obj1 = *itr;
        if(!obj1->isCollidingDown()){
            obj1->fall();
        }
    }
}

void World::collisionManager(){
    for(auto itr = things.begin(); itr != things.end(); ++itr){
        Thing* obj1 = *itr;
        obj1->setCollidingUp(false);
        obj1->setCollidingRight(false);
        obj1->setCollidingLeft(false);
        obj1->setCollidingDown(false);
    }
    for(auto itr1 = things.begin(); itr1 != things.end(); ++itr1){
        Thing* obj1 = *itr1;
        if(!obj1->isCollisionEnabled()) continue;
        for(auto itr2 = things.begin(); itr2 != things.end(); ++itr2){
            Thing* obj2 = *itr2;
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

float World::getDistance(sf::Vector2f p1, sf::Vector2f p2){
    return sqrt(pow(p1.x-p2.x,2.0) + pow(p1.y-p2.y,2.0));
}
