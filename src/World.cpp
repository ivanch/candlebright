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
                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) < 75) continue; // Range
               // (*itr2)->takeDamage(*itr, (*itr)->getDamage());

                if((*itr2)->getHealth() <= 0) characters.remove(*itr2);
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
    for(auto itr = objects.getFirst(); itr != NULL; itr = itr->getNext()){
        Thing* obj1 = itr->getData();
        if(!obj1->isCollidingDown()){
            obj1->fall();
        }
    }
}

void World::collisionManager(){
    for(auto itr1 = objects.getFirst(); itr1 != NULL; itr1 = itr1->getNext()){
        Thing* obj1 = itr1->getData();
        obj1->setCollidingUp(false);
        obj1->setCollidingRight(false);
        obj1->setCollidingLeft(false);
        obj1->setCollidingDown(false);
    }
    for(auto itr1 = objects.getFirst(); itr1 != NULL; itr1 = itr1->getNext()){
        Thing* obj1 = itr1->getData();
        if(!obj1->isCollisionEnabled()) continue;
        for(auto itr2 = itr1; itr2 != NULL; itr2 = itr2->getNext()){
            Thing* obj2 = itr2->getData();
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
