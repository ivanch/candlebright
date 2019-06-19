#include "Game.hpp"

Game::Game():   menu(engine.getWindow()->getSize().x,engine.getWindow()->getSize().y) {
    window = engine.getWindow();
    view.reset(sf::FloatRect(0.f, 300.f, 600.f, 500.f));
    srand (static_cast <unsigned> (time(NULL)));
    game_paused = false;

    player1 = new Player(1);
    player2 = new Player(2);

    spawnDelay = 5; // Spawna um inimigo na tela a cada 15 segundos
}
Game::~Game(){}

void Game::run(){
    while(menu.isEnabled()){ // Roda o menu primeiro...
        engine.clearWindow();
        menu.update(&engine);
        menu.draw(&engine);
        engine.render();
    }
    if(menu.getSelectedPhase() == 1){
        world = new City;
        act_world = 1;
    }else if(menu.getSelectedPhase() == 2){
        world = new Cemitery;
        act_world = 2;
    }

    world->addCharacter(player1); // Sempre haverá um jogador por padrão
    if(menu.getSelectedPlayers() == 2){
        world->addCharacter(player2);
    }

    engine.getWindow()->setView(view);
    update(); // Roda o jogo...
}
void Game::saveGame()
{
    ofstream file("Save/GameSave.txt");

    if(file.is_open())
    {
        file << act_world << endl;
        for(auto itr = world->getCharList()->begin(); itr != world->getCharList()->end(); ++itr){
            file << (*itr)->getType() << "," << (*itr)->getSubType() << "," << (*itr)->getHealth() << ',' << (*itr)->getPos().x << ',' << (*itr)->getPos().y << endl;
        }
        cout << "Game Saved" << endl;

    }
    file.close();
}
void Game::loadPlayers(){
    /* Carrega os Players */
    string line;
    ifstream file("Save/GameSave.txt");
    Player* temp_player;
    int player_count = 0;
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
            if(type != 0) continue;

            line = line.substr(line.find(',') + 1, line.size());
            int subtype = std::stoi(line.substr(0, line.find(',') + 1));

            line = line.substr(line.find(',') + 1, line.size());
            float health = std::stoi(line.substr(0, line.find(',') + 1));

            line = line.substr(line.find(',') + 1, line.size());
            float px = std::stof(line.substr(0, line.find(',') + 1));
            line = line.substr(line.find(',') + 1, line.size());
            float py = std::stof(line);

            player_count++;
            temp_player = new Player(player_count);
            temp_player->setPos({px,py});
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
            menu.draw(&engine);
        }else{
            if(world == NULL){
                cerr << "Mundo não inicializado" << endl;
                return;
            }
            /* Movimentação do View */
            if(player1->getPos().x >= (view.getCenter().x+view.getSize().x/2)-50 && player2->getPos().x <= (view.getCenter().x-view.getSize().x/2)+50)
                player1->setCollidingRight(true);
            else if(player1->getPos().x <= (view.getCenter().x-view.getSize().x/2)+50  && player2->getPos().x >= (view.getCenter().x+view.getSize().x/2)-50)
                player1->setCollidingLeft(true);
            if(player1->getPos().x - (view.getCenter().x+((view.getSize().x)/2))  > -50)
                view.move({1.5,0});
            if(player1->getPos().x - (view.getCenter().x+((view.getSize().x)/2))  < -550)
                view.move({-1.5,0});
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
                world->drawAll(&engine); // Desenha todas entidades do mundo

                /* Spawn aleatório */
                if(spawnTimer.getElapsedTime().asSeconds() >= spawnDelay){
                    Enemy* e;
                    int r = rand()%4;
                    sf::Vector2f pos = world->getRandomPosition(view);

                    if(r == 0){ // Zombie
                        e = new Zombie(pos);
                    }else if(r == 1){ // Clothed Zombie
                        e = new Dressed_Zombie(pos);
                    }else if(r == 2){ // Ghost
                        e = new Ghost(pos);
                    }else if(r == 3){ // Hell Demon
                        e = new Hell_Demon(pos);
                    }

                    world->addCharacter(e);

                    spawnTimer.restart();
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
        }
        engine.render();
    }
}
