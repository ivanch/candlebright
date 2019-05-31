#include "Game.hpp"

Game::Game():   player(engine.getView()),
                menu(engine.getWindow()->getSize().x,engine.getWindow()->getSize().y) {
    window = engine.getWindow();
    menuEnabled = true;
}
Game::~Game(){}

void Game::run(){
    player.setEngine(&engine);
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
        if(menuEnabled){
            menu.draw(window);
            sf::Event event;
            while (window->pollEvent(event)){
                switch(event.type)
                {
                    case sf::Event::KeyReleased:
                        switch(event.key.code)
                        {
                            case sf::Keyboard::Up:
                                menu.moveUp();
                            break;
                            case sf::Keyboard::Down:
                                menu.moveDown();
                            break;
                            case sf::Keyboard::Return:
                                switch(menu.getEnter())
                                {
                                    case 0:
                                        {
                                            cout<<"Jogar pressionado"<<endl;
                                            menuEnabled=false;
                                            world = new World_1;
                                            world->setAllEngine(&engine);
                                        }
                                    break;
                                    case 1:
                                        cout<<"Opcao pressionado"<<endl;
                                    break;
                                    case 2:
                                        window->close();
                                    break;
                                    default: break;

                                }
                        }
                        break;
                    case sf::Event::Closed:
                        window->close();
                    default: break;
                    break;
                }
            }
        }else{
            if(world == NULL){
                cerr << "Mundo não inicializado" << endl;
                return;
            }
            gravity();

            engine.setView();

            if(gordolaClock.getElapsedTime().asMilliseconds() >= 250){
                if(gordolaRect.left == 160){
                    gordolaRect.left = 0;
                }else gordolaRect.left += 40;
                gordola.setTextureRect(gordolaRect);
                gordolaClock.restart();
            }
            engine.draw(*world->getBackground());
            window->draw(gordola);

            player.update(); // Atualiza o jogador
            world->update(); // Atualiza as entidades do mundo
        }
        engine.render();
    }
}

void Game::gravity(){
    for(auto itr = Entity::entities.begin(); itr != Entity::entities.end(); ++itr){
        if(!ColisionManager::intersectsDown((*itr)->getRect())){
            (*itr)->fall();
        }
    }
}