#include "Engine.hpp"

Engine::Engine(sf::RenderWindow& _win,  sf::View& _view):
    window(_win), view(_view), world(NULL), menu(window.getSize().x,window.getSize().y){
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 350);
    window.create(sf::VideoMode(600, 400), "Joguinho!", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);
    menuEnabled = true;
}
Engine::~Engine(){}

void Engine::addPlayer(Player* p){
    listeners.push_back(dynamic_cast<Listener*>(p));
}

void Engine::addSprite(sf::Sprite* spr){
    sprites.push_back(spr);
}

void Engine::update(){
    while (window.isOpen()){
        window.clear();
        if(menuEnabled){
            menu.draw(window);
            sf::Event event;
            while (window.pollEvent(event)){
                switch(event.type)
                {
                    case sf::Event::KeyReleased:
                        switch(event.key.code)
                        {
                            case sf::Keyboard::Up:
                                menu.moveUp();
                            case sf::Keyboard::Down:
                                menu.moveDown();
                            break;
                            case sf::Keyboard::Return:
                                switch(menu.getEnter())
                                {
                                    case 0:
                                        cout<<"Jogar pressionado"<<endl;
                                    break;
                                    case 1:
                                        cout<<"Opcao pressionado"<<endl;
                                    break;
                                    case 2:
                                        window.close();
                                    break;
                                    default: break;

                                }
                        }
                        break;
                    case sf::Event::Closed:
                        window.close();
                    default: break;
                    break;
                }
            }
        }else{
            window.setView(view);

            for(auto itr = sprites.begin(); itr != sprites.end(); ++itr){
                window.draw(*(*itr));
            }

            world->draw(window);
            world->gravity();

            for(auto itr = listeners.begin(); itr != listeners.end(); ++itr){
                (*itr)->onUpdate();
                (*itr)->drawTo(window);
            }
        }
        window.display();
    }
}
