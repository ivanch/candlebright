#include "World.hpp"

World::World(){}
World::~World(){}

void World::update(){
    col_mngr.checkCollisions(&things);
    for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->update();
    }
    for(auto itr = characters.begin(); itr != characters.end(); ++itr){
        if((*itr)->isAttacking()){
            for(auto itr2 = characters.begin(); itr2 != characters.end(); ++itr2){
                if(itr == itr2) continue; // auto-dano
                cout << getDistance((*itr)->getPos(), (*itr2)->getPos()) << endl;
                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) > 75.0) continue; // Range

                //if((*itr2)->getHealth()-(*itr)->getDamage() <= 0){
                    //entities.remove(*itr2);
                    //things.remove(*itr2);
                    //characters.remove(*itr2);
                //}
                (*itr2)->takeDamage(*itr, (*itr)->getDamage());
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

float World::getDistance(sf::Vector2f p1, sf::Vector2f p2){
    return sqrt(pow(p1.x-p2.x,2.0) + pow(p1.y-p2.y,2.0));
}
