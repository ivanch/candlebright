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
                                            world->addEntity(static_cast<Entity*>(&player));
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
            world->gravity();

            world->update(); // Atualiza as entidades do mundo
        }
        engine.render();
    }
}