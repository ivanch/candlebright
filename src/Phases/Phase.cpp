#include "Phase.hpp"

Phase::Phase(){}
Phase::~Phase(){}

void Phase::update(){
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

            if((*itr)->getType() == 2){ // Fogo
                if(getDistance((*itr)->getPos(), (*itr2)->getPos()) > 50.0) continue; // Range

                (*itr2)->takeDamage(static_cast<Thing*>(*itr), (*itr)->getDamage());

                if((*itr2)->getHealth() <= 0){
                    bufferKill.insert(*itr2);
                }
            }else if((*itr)->getType() == 3){ // Black Hole
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

void Phase::drawAll(Engine* engine){
    draw(engine);
    /*for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->draw(engine);
    }*/
    for(auto itr = entities.begin(); itr != entities.end(); ++itr){
        (*itr)->draw(engine);
    }
}

void Phase::draw(Engine* engine){
    engine->draw(*background);
}

void Phase::gravity(){
    for(auto itr = things.begin(); itr != things.end(); ++itr){
        Thing* obj1 = *itr;
        if(!obj1->isCollidingDown()){
            obj1->fall();
        }
    }
}

float Phase::getDistance(sf::Vector2f p1, sf::Vector2f p2){
    return sqrt(pow(p1.x-p2.x,2.0) + pow(p1.y-p2.y,2.0));
}

void Phase::loadEnemies(int act_world){
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
                    enemy = new Dressed_Zombie({px,py});
                }
                else if(subtype == 3)
                {
                    enemy = new Ghost({px,py});
                }
                else if(subtype == 4)
                {
                    enemy = new Hell_Demon({px,py});
                }
                else if(subtype == 5)
                {
                    enemy = new Sylathus({px,py});
                }
            }
            enemy->setHealth(health);
            addCharacter(enemy);
        }
        file.close();
    }
}

sf::Vector2f Phase::getRandomPosition(const sf::View& view){
    sf::Vector2f pos = {0,0};

    float   left    = view.getCenter().x - view.getSize().x/2,
            right   = view.getCenter().x + view.getSize().x/2;

    float   top     = view.getCenter().y - view.getSize().y/2,
            bottom  = view.getCenter().y + view.getSize().y/2;

    float   random_x,
            random_y;

    int     tries = 0;

    while(tries < 1000){
        tries++;

        random_x = left + static_cast <float> (rand()) / ( static_cast <float> ( RAND_MAX/(right-left) ));
        random_y = top  + static_cast <float> (rand()) / ( static_cast <float> ( RAND_MAX/(bottom-top) ));

        pos = {random_x, random_y};

        /* Determina melhor Y */
        bool _best_y_success = false;
        float _best_distance = -1.0;
        float _best_y = 0.0;
        for(auto itr = obstacles.begin(); itr != obstacles.end(); ++itr){
            if((*itr)->getType() != 0) continue; // Spawn apenas em cima de plataformas
            if((*itr)->getRect().left > random_x && (*itr)->getRect().left+(*itr)->getRect().width < random_x) continue; // random_x fora das bordas da Plataforma
            float _dist = getDistance(pos,(*itr)->getPos());
            if(_dist < _best_distance || _best_distance == -1.0){
                _best_y = (*itr)->getRect().top+5.0;
                _best_distance = _dist;
            }
            _best_y_success = true;
        }
        if(!_best_y_success) continue;
        /* Melhor Y determinado */

        pos = {random_x, _best_y};

        /* Testa posição de Personagens */
        bool _char_test_success = true;
        for(auto itr = characters.begin(); itr != characters.end(); ++itr){
            if(getDistance(pos,(*itr)->getPos()) < 25.0){
                _char_test_success = false;
                break;
            }
        }
        if(!_char_test_success) continue;
        /* Passou pelo teste de Personagens */

        break;
    }

    if(tries == 1000){
        cerr << "Erro ao tentar achar alguma posição aleatória dentro do mapa" << endl;
        return {0,0};
    }

    cout << pos.y << endl;
    return pos;
}