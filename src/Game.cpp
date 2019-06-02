#include "Game.hpp"

Game::Game():   player(engine.getView()),
                menu(engine.getWindow()->getSize().x,engine.getWindow()->getSize().y) {
    window = engine.getWindow();
    world = new World_1;
    world->addEntity(static_cast<Entity*>(&player));
    world->setAllEngine(&engine);
}
Game::~Game(){}

void Game::run(){
    player.setEngine(&engine);
    menu.setEngine(&engine);
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
            menu.update();
        }else{
            if(world == NULL){
                cerr << "Mundo não inicializado" << endl;
                return;
            }
            world->gravity();

            world->update(); // Atualiza as entidades do mundo
        }
        engine.render();
    }
}