#include "Phase.hpp"

Phase::Phase(): col_mngr(&things){

}
Phase::~Phase(){}

void Phase::update(){
    col_mngr.checkCollisions();
    //for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
    for(auto itr = entities.begin(); itr != entities.end(); ++itr){
        (*itr)->update();
    }

    std::set<Character*> killBuffer;
    checkAttack(&killBuffer);
    checkObstacles(&killBuffer);
    for(auto chr = killBuffer.begin(); chr != killBuffer.end(); ++chr){
        things.remove(*chr);
        characters.remove(*chr);
        if((*chr)->getType() != 0){
            entities.remove(*chr); // Continua imprimindo jogadores mortos na tela
            delete *chr;
        }else{
            (*chr)->death();
        }
    }
}

void Phase::drawAll(Engine& engine){
    draw(engine);
    /*for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->draw(engine);
    }*/
    for(auto itr = entities.begin(); itr != entities.end(); ++itr){
        (*itr)->draw(engine);
    }
}

void Phase::draw(Engine& engine){
    engine.draw(*background);
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
    std::string line;
    std::ifstream file("Save/GameSave.txt");
    Enemy* enemy;
    if(file.is_open())
    {
        getline(file,line);
        if(act_world != std::stoi(line))
        {
            std::cerr << "Mundo não condizente com o jogo já salvo." << std::endl;
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
        bool best_y_success = false;
        float best_distance = -1.0;
        float best_y = 0.0;
        for(auto plt = obstacles.begin(); plt != obstacles.end(); ++plt){
            if((*plt)->getType() != 0) continue; // Spawn apenas em cima de plataformas
            if(random_x < (*plt)->getRect().left && random_x > (*plt)->getRect().left+(*plt)->getRect().width) continue; // random_x fora das bordas da Plataforma
            float dist = abs(pos.y-(*plt)->getRect().top);
            if(dist > best_distance || best_distance == -1.0){
                best_y = (*plt)->getRect().top;
                best_distance = dist;
            }
            best_y_success = true;
        }
        if(!best_y_success) continue;
        /* Melhor Y determinado */

        pos = {random_x, best_y};

        /* Testa posição de outros Obstáculos */
        bool obstacles_test_success = true;
        for(auto obs = obstacles.begin(); obs != obstacles.end(); ++obs){
            if((*obs)->getType() == 0 || (*obs)->getType() == 1) continue; // Ignora plataformas
            if(getDistance(pos,(*obs)->getPos()) < (*obs)->getRange() + 15.0){
                obstacles_test_success = false;
                break;
            }   
        }
        if(!obstacles_test_success) continue;
        /* Passou pelo teste de Obstáculos */

        /* Testa posição de Personagens */
        bool char_test_success = true;
        for(auto chr = characters.begin(); chr != characters.end(); ++chr){
            if(getDistance(pos,(*chr)->getPos()) < 100.0){
                char_test_success = false;
                break;
            }
        }
        if(!char_test_success) continue;
        /* Passou pelo teste de Personagens */

        break;
    }

    if(tries == 1000){
        std::cerr << "Erro ao tentar achar alguma posição aleatória dentro do mapa" << std::endl;
        return {0,0};
    }

    return pos;
}

void Phase::checkAttack(std::set<Character*>* killBuffer){
    for(auto issuer = characters.begin(); issuer != characters.end(); ++issuer){
        if( (*issuer)->getState() == CharacterState::STATE_ATTACKING && 
            (*issuer)->getAttackClock()->getElapsedTime().asMilliseconds() >= (*issuer)->getAttackSpeed()){
            for(auto damaged = characters.begin(); damaged != characters.end(); ++damaged){
                /* Exclusões */
                if(issuer == damaged) continue; // auto-dano
                if((*issuer)->getType() == (*damaged)->getType()) continue; // Não ataca personagens do mesmo tipo
                if(getDistance((*issuer)->getPos(), (*damaged)->getPos()) > (*issuer)->getRange()) continue; // Fora do range

                if((*issuer)->getFacing() == Character::FACING_RIGHT && (*damaged)->getPos().x < (*issuer)->getPos().x) continue; // Previnir ataques de costas
                if((*issuer)->getFacing() == Character::FACING_LEFT  && (*damaged)->getPos().x > (*issuer)->getPos().x) continue; // Previnir ataques de costas
                
                (*damaged)->takeDamage((*issuer)->getDamage());

                if((*damaged)->getHealth() <= 0){ // Não adiciona player na lista pra matar
                    killBuffer->insert(*damaged);
                }
            }
            (*issuer)->getAttackClock()->restart();
        }
    }
}

void Phase::checkObstacles(std::set<Character*>* killBuffer){
    for(auto obs = obstacles.begin(); obs != obstacles.end(); ++obs){
        if((*obs)->getAttackClock()->getElapsedTime().asMilliseconds() < (*obs)->getAttackRate()) continue; // Attack rate
        for(auto chr = characters.begin(); chr != characters.end(); ++chr){
            if((*chr)->getType() != 0) continue; // Só afeta players

            if((*obs)->getType() == 2){ // Fogo
                if(getDistance((*obs)->getPos(), (*chr)->getPos()) > (*obs)->getRange()) continue; // Range

                (*chr)->takeDamage((*obs)->getDamage());

                if((*chr)->getHealth() <= 0){
                    killBuffer->insert(*chr);
                }
            }else if((*obs)->getType() == 3){ // Black Hole
                if(getDistance((*obs)->getPos(), (*chr)->getPos()) > (*obs)->getRange()) continue; // Range

                if(getDistance((*obs)->getPos(), (*chr)->getPos()) < (*obs)->getRange()*0.2){
                    (*chr)->takeDamage((*obs)->getDamage());

                    if((*chr)->getHealth() <= 0){
                        killBuffer->insert(*chr);
                    }
                }
                
                if((*chr)->getPos().x < (*obs)->getPos().x){ // Player a esquerda do buraco
                    (*chr)->move({3,0});
                }else{
                    (*chr)->move({-3,0});
                }
            }
        }
        (*obs)->getAttackClock()->restart();
    }
}