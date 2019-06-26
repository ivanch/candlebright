#include "Game.hpp"

Game::Game():   menu(engine.getWindow()->getSize().x,engine.getWindow()->getSize().y){
    window = engine.getWindow();
    view.reset(sf::FloatRect(0.0f, 300.0f, 600.0f, 500.0f));
    game_paused = false;

    player1 = new Player(1);
    player2 = new Player(2);

    enemySpawnDelay = 25; // Spawna um inimigo na tela a cada 25 segundos
    obstacleSpawnDelay = 45; // Spawna um obstáculo a cada 45 segundos

    //text={};

    if (!font.loadFromFile("fonts/ancient.ttf"))
    {
        std::cerr<<"Erro ao carregar fonte"<<std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(42);
    text.setString("Ranking\n");
    text.setPosition(200,350);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(1);
    ranking==false;
}
Game::~Game(){ }

void Game::run(){
    while(menu.isEnabled()){ // Roda o menu primeiro...
        engine.clearWindow();
        menu.update(&engine);
        menu.draw(engine);
        engine.render();
    }
    if(menu.getSelectedPhase() == 1){
        world = new Phases::City;
        act_world = 1;
    }else if(menu.getSelectedPhase() == 2){
        world = new Phases::Cemitery;
        act_world = 2;
    }

    world->addCharacter(player1); // Sempre haverá um jogador por padrão
    player1->setPosition(world->getSpawnPoint());
    if(menu.getSelectedPlayers() == 2){
        world->addCharacter(player2);
        player2->setPosition(sf::Vector2f(world->getSpawnPoint().x,
                                     world->getSpawnPoint().y-100 ) );
    }

    engine.getWindow()->setView(view);
    update(); // Roda o jogo...
}
void Game::saveGame()
{
    std::ofstream file("Save/GameSave.txt");

    if(file.is_open())
    {
        file << act_world << std::endl;
        std::set<Character *>::iterator itr;
        for(itr = world->getCharList()->begin(); itr != world->getCharList()->end(); ++itr){
            file << (*itr)->getType() << "," << (*itr)->getSubType() << "," << (*itr)->getHealth() << ',' << (*itr)->getPosition().x << ',' << (*itr)->getPosition().y - 30.0f << std::endl;
        if((*itr)->getType() == 0){
            std::cout<<Player::getScore();
            file << Player::getScore() << std::endl;
        }
        }
        std::cout << "Game Saved" << std::endl;

    }
    file.close();
}
void Game::loadPlayers(){
    /* Carrega os Players */
    std::string line;
    std::ifstream file("Save/GameSave.txt");
    Player* temp_player;
    int player_count = 0;
    if(file.is_open())
    {
        getline(file,line);
        if(act_world != getIntFromString(line))
        //if(act_world != std::stoi(line))
        {
            std::cerr << "Mundo não condizente com o jogo previamente salvo." << std::endl;
            return;
        }
        while (getline(file,line))
        {
            int type = getIntFromString(line.substr(0, line.find(',') + 1));
            if(type != 0) continue;

            line = line.substr(line.find(',') + 1, line.size()); // Pula sub-tipo

            line = line.substr(line.find(',') + 1, line.size());
            float health = getIntFromString(line.substr(0, line.find(',') + 1));

            line = line.substr(line.find(',') + 1, line.size());
            float px = getFloatFromString(line.substr(0, line.find(',') + 1));
            line = line.substr(line.find(',') + 1, line.size());
            float py = getFloatFromString(line);

            player_count++;
            temp_player = new Player(player_count);
            temp_player->setPosition(sf::Vector2f(px, py));
            temp_player->setHealth(health);

            if(player_count == 1) player1 = temp_player;
            else if(player_count == 2) player2 = temp_player;
            world->addCharacter(temp_player);
        }
    }
}
void Game::update(){
    while (engine.isWindowOpen()){
        engine.clearWindow();
        if(menu.isEnabled()){
            menu.update(&engine);
            menu.draw(engine);
        }else{
            if(world == NULL){
                std::cerr << "Mundo não inicializado" << std::endl;
                return;
            }
            /* Movimentação do View */
            if(player1->getPosition().x >= (view.getCenter().x+view.getSize().x/2)-150 && player2->getPosition().x <= (view.getCenter().x-view.getSize().x/2)+150)
                player1->setCollidingRight(true);
            else if(player1->getPosition().x <= (view.getCenter().x-view.getSize().x/2)+150  && player2->getPosition().x >= (view.getCenter().x+view.getSize().x/2)-150)
                player1->setCollidingLeft(true);
            if(player1->getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  > -100)
                view.move(sf::Vector2f(1.5, 0));
            if(player1->getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  < -500)
                view.move(sf::Vector2f(-1.5, 0));
            engine.getWindow()->setView(view);

            /* Pausa o jogo */
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && timer.getElapsedTime().asSeconds() > 0.2)
            {
                game_paused = !game_paused;
                timer.restart();
            }

            if(!game_paused){
                /* Atualizações no mundo */
                world->gravity();
                world->update(); // Atualiza as entidades do mundo

                if(enemySpawnTimer.getElapsedTime().asSeconds() >= enemySpawnDelay) spawnRandomEnemy();
                if(obstacleSpawnTimer.getElapsedTime().asSeconds() >= obstacleSpawnDelay) spawnRandomObstacle();

                if(Enemy::enemyCount == 0){
                    nextPhase();
                }
            }

            /* Botão pra carregar e salvar */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5)&& timer.getElapsedTime().asSeconds() > 1)
            {
                saveGame();
                timer.restart();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F6)&& timer.getElapsedTime().asSeconds() > 1)
            {
                world->loadEnemies(act_world);
                loadPlayers();
                timer.restart();
            }
            world->drawAll(engine); // Desenha todas entidades do mundo
            if(player1->isDead())
                engine.draw(text);
            if(player1->isDead() && ranking==false)
            {
                std::string buffer;
                std::ifstream ifile("Save/Ranking.txt");
                while(getline(ifile,buffer))
                {
                    text.setString(text.getString()+ '\n' + buffer);
                    engine.draw(text);
                }
                ranking = true;
            }
        }
        engine.render();
    }
}

/* Spawn aleatório de inimigos */
void Game::spawnRandomEnemy(){
    Enemy* e;
    int r;
    if(act_world == 1) r = rand()%2;
    else if(act_world == 2) r = rand()%4;
    sf::Vector2f pos = world->getRandomPosition(view);
    if(pos.x != 0 && pos.y != 0){
        if(r == 0){ // Spawn em ambas fases
            e = new Zombie(sf::Vector2f(pos.x, pos.y-60));
        }else if(r == 1){ // Spawn em ambas fases
            e = new Dressed_Zombie(sf::Vector2f(pos.x, pos.y-60));
        }else if(r == 2){ // Spawn apenas na fase 2
            e = new Ghost(sf::Vector2f(pos.x, pos.y-70));
        }else if(r == 3){ // Spawn apenas na fase 2
            e = new Hell_Demon(sf::Vector2f(pos.x, pos.y-70));
        }
        world->addCharacter(e);
    }
    enemySpawnTimer.restart();
}

/* Spawn aleatório de obstáculos */
void Game::spawnRandomObstacle(){
    Obstacles::Obstacle* o;
    int r = rand()%100;
    sf::Vector2f pos = world->getRandomPosition(view);
    if(pos.x != 0 && pos.y != 0){
        int _size = 5 + rand()%(55-5); // 5 ~ 50
        if(r <= 80){ // Fogo (80% de chance)
            o = new Obstacles::Fire(sf::Vector2f(pos.x, pos.y-(_size)), _size);
        }else if(r > 80){ // Black Hole (20% de chance)
            o = new Obstacles::Black_Hole(sf::Vector2f(pos.x, pos.y), _size);
        }
        world->addObstacle(o);
    }
    obstacleSpawnTimer.restart();
}

void Game::nextPhase(){
    if(act_world == 1){
        delete world;
        world = new Phases::Cemitery;
        act_world = 2;

        player1 = new Player(1);

        world->addCharacter(player1); // Sempre haverá um jogador por padrão
        player1->setPosition(world->getSpawnPoint());
        if(menu.getSelectedPlayers() == 2){
            player2 = new Player(2);
            world->addCharacter(player2);
            player2->setPosition(sf::Vector2f(world->getSpawnPoint().x,
                                         world->getSpawnPoint().y-100 ) );
        }
    }else{
        engine.getWindow()->close();
    }
}

const int Game::getIntFromString(const std::string& _str) const {
    int result;
    sscanf(_str.c_str(), "%d", &result);
    return result;
}

const float Game::getFloatFromString(const std::string& _str) const {
    float result;
    sscanf(_str.c_str(), "%f", &result);
    return result;
}
