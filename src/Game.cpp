#include "Game.hpp"

Game::Game():   player1(1),
                player2(2),
                menu(engine.getWindow()->getSize().x,engine.getWindow()->getSize().y) {
    window = engine.getWindow();
    menu.setEngine(&engine);
}
Game::~Game(){}

void Game::run(){
    while(menu.isEnabled()){ // Roda o menu primeiro...
        engine.clearWindow();
        menu.update();
        engine.render();
    }
    if(menu.getSelectedWorld() == 1){
        world = new World_1;
    }else if(menu.getSelectedWorld() == 2){
        world = new World_2;
    }
    world->setAllEngine(&engine);

    world->addObject(&player1); // Sempre haverá um jogador por padrão
    player1.setEngine(&engine);
    if(menu.getSelectedPlayers() == 2){
        world->addObject(&player2);
        player2.setEngine(&engine);
    }

    update(); // Roda o jogo...
}

void Game::update(){
    sf::IntRect gordolaRect(0,0,40,47);
    sf::Clock gordolaClock;
    sf::Texture gordolaTexture;
    gordolaTexture.loadFromFile("sprites/GordolaSheet.png");

    sf::Sprite gordola(gordolaTexture, gordolaRect);
    gordola.setPosition({280,670});

    while (engine.isWindowOpen()){
        engine.clearWindow();
        if(world == NULL){
            cerr << "Mundo não inicializado" << endl;
            return;
        }
        world->gravity();

        world->update(); // Atualiza as entidades do mundo
        engine.render();
    }
}