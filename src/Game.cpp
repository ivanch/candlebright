#include "Game.hpp"

Game::Game():   player(engine.getView()),
                menu(engine.getWindow()->getSize().x,engine.getWindow()->getSize().y) {
    window = engine.getWindow();
    world = new World_1;
    world->addObject(&player);
}
Game::~Game(){}

void Game::run(){
    update();
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