#include "World.hpp"

World::World(){}
World::~World(){}

void World::update(){
    col_mngr.checkCollisions(&things);
    //for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
    for(auto itr = entities.begin(); itr != entities.end(); ++itr){
        (*itr)->update();
    }

    set<Character*> bufferKill;
    for(auto itr = characters.begin(); itr != characters.end(); ++itr){
        if( (*itr)->getState() == CharacterState::STATE_ATTACKING && 
            (*itr)->getAttackClock()->getElapsedTime().asMilliseconds() >= (*itr)->getAttackSpeed()){
            for(auto itr2 = characters.begin(); itr2 != characters.end(); ++itr2){
                /* Exclusões */
                if(itr == itr2) continue; // auto-dano
                if((*itr)->getType() == (*itr2)->getType()) continue; // Não ataca personagens do mesmo tipo
                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) > 75.0) continue; // Range
                if((*itr)->getFacing() == Character::FACING_RIGHT && (*itr2)->getPos().x < (*itr)->getPos().x) continue; // Previnir ataques de costas
                if((*itr)->getFacing() == Character::FACING_LEFT && (*itr2)->getPos().x > (*itr)->getPos().x) continue; // Previnir ataques de costas
                
                (*itr2)->takeDamage(static_cast<Thing*>(*itr), (*itr)->getDamage());

                if((*itr2)->getHealth() <= 0){
                    bufferKill.insert(*itr2);
                }
            }
            (*itr)->getAttackClock()->restart();
        }
    }
    for(auto itr = obstacles.begin(); itr != obstacles.end(); ++itr){
        if((*itr)->getAttackClock()->getElapsedTime().asMilliseconds() < (*itr)->getAttackRate()) continue; // Attack rate
        for(auto itr2 = characters.begin(); itr2 != characters.end(); ++itr2){
            if((*itr2)->getType() != 0) continue; // Só afeta players

            if((*itr)->getType() == 1){ // Fogo
                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) > 50.0) continue; // Range

                (*itr2)->takeDamage(static_cast<Thing*>(*itr), (*itr)->getDamage());

                if((*itr2)->getHealth() <= 0){
                    bufferKill.insert(*itr2);
                }
            }else if((*itr)->getType() == 2){ // Black Hole
                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) > 200.0) continue; // Range

                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) < 50.0){
                    (*itr2)->takeDamage(static_cast<Thing*>(*itr), (*itr)->getDamage());

                    if((*itr2)->getHealth() <= 0){
                        bufferKill.insert(*itr2);
                    }
                }
                
                if((*itr2)->getPos().x < (*itr)->getPos().x){ // Player a esquerda do buraco
                    (*itr2)->move({3,0});
                }else{
                    (*itr2)->move({-3,0});
                }
            }
        }
        (*itr)->getAttackClock()->restart();
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
    /*for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->draw(engine);
    }*/
    for(auto itr = entities.begin(); itr != entities.end(); ++itr){
        (*itr)->draw(engine);
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

void World::loadEnemies(int act_world){
    /* Remove todos os Characters */
    while(!characters.characters.empty()){
        entities.remove(*characters.begin());
        things.remove(*characters.begin());
        characters.remove(*characters.begin());
    }

    /* Carrega os Inimigos */
    string line;
    ifstream file("Save/GameSave.txt");
    Enemy* enemy;
    if(file.is_open())
    {
        getline(file,line);
        if(act_world != std::stoi(line))
        {
            cerr << "Mundo não condizente com o jogo já salvo." << endl;
            return;
        }
        while (getline(file,line))
        {
            int type = std::stoi(line.substr(0, line.find(',') + 1));
            if(type != 1) continue;

            line = line.substr(line.find(',') + 1, line.size());
            int subtype = std::stoi(line.substr(0, line.find(',') + 1));

            line = line.substr(line.find(',') + 1, line.size());
            float health = std::stoi(line.substr(0, line.find(',') + 1));

            line = line.substr(line.find(',') + 1, line.size());
            float px = std::stof(line.substr(0, line.find(',') + 1));
            line = line.substr(line.find(',') + 1, line.size());
            float py = std::stof(line);

            if(type == 1) // Inimigo
            {
                if(subtype == 1)
                {
                    enemy = new Zombie({px,py});
                }
                else if(subtype == 2)
                {
                    enemy = new ClothedZombie({px,py});
                }
                else if(subtype == 3)
                {
                    enemy = new Ghost({px,py});
                }
                else if(subtype == 4)
                {
                    enemy = new HellDemon({px,py});
                }
                else if(subtype == 5)
                {
                    enemy = new Sylathus({px,py});
                }
            }
            enemy->setPos({px,py});
            enemy->setHealth(health);
            addCharacter(enemy);
        }
        file.close();
    }
}