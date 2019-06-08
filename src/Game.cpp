#include "Game.hpp"

Game::Game():   player1(1),
                player2(2),
                menu(engine.getWindow()->getSize().x,engine.getWindow()->getSize().y) {
    window = engine.getWindow();
    world = new World_1;
}
Game::~Game(){}

void Game::run(){
    while(menu.isEnabled()){ // Roda o menu primeiro...
        engine.clearWindow();
        menu.update(&engine);
        menu.draw(&engine);
        engine.render();
    }
    if(menu.getSelectedWorld() == 1){
        world = new World_1;
    }else if(menu.getSelectedWorld() == 2){
        world = new World_2;
    }

    world->addObject(&player1); // Sempre haverá um jogador por padrão
    if(menu.getSelectedPlayers() == 2){
        world->addObject(&player2);
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
        if(menu.isEnabled()){
            menu.update(&engine);
            menu.draw(&engine);
        }else{
            if(world == NULL){
                cerr << "Mundo não inicializado" << endl;
                return;
            }
            world->gravity();

            world->update(); // Atualiza as entidades do mundo
            world->drawAll(&engine); // Desenha todas entidades do mundo
        }
        engine.render();
    }
}