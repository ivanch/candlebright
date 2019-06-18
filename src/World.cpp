#include "World.hpp"

World::World(){}
World::~World(){}

void World::update(){
    col_mngr.checkCollisions(&things);
    for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->update();
    }

    set<Character*> bufferKill;
    for(auto itr = characters.begin(); itr != characters.end(); ++itr){
        if((*itr)->getState() == CharacterState::STATE_ATTACKING){
            for(auto itr2 = characters.begin(); itr2 != characters.end(); ++itr2){
                /* Exclusões */
                if(itr == itr2) continue; // auto-dano
                if((*itr)->getType() == (*itr2)->getType()) continue; // Não ataca personagens do mesmo tipo
                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) > 75.0) continue; // Range
                if((*itr2)->getType() == 0) continue; // Player não morre
                if((*itr)->getFacing() == Character::FACING_RIGHT && (*itr2)->getPos().x < (*itr)->getPos().x) continue; // Previnir ataques de costas
                if((*itr)->getFacing() == Character::FACING_LEFT && (*itr2)->getPos().x > (*itr)->getPos().x) continue; // Previnir ataques de costas

                cout << getDistance((*itr)->getPos(), (*itr2)->getPos()) << endl;
                
                (*itr2)->takeDamage(*itr, (*itr)->getDamage());

                if((*itr2)->getHealth() <= 0){
                    bufferKill.insert(*itr2);
                }
            }
            //if((*itr)->getType() != 2) (*itr)->setState(CharacterState::STATE_IDLE);
        }
    }
    
    for(auto itr = bufferKill.begin(); itr != bufferKill.end(); ++itr){
        if((*itr)->getHealth() <= 0){
            entities.remove(*itr);
            things.remove(*itr);
            characters.remove(*itr);
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
