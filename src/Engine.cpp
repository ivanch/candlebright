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

void Engine::update(){
    sf::IntRect rect(0,0,40,47);
    sf::Clock clock;
    sf::Texture gordola;
    gordola.loadFromFile("sprites/GordolaSheet.png");

    sf::Sprite sprite(gordola, rect);
    sprite.setPosition({280,670});
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
                                        }
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

            for(auto itr = Listener::listeners.begin(); itr != Listener::listeners.end(); ++itr){
                (*itr)->onUpdate();
            }

            if(clock.getElapsedTime().asMilliseconds() >= 250){
                if(rect.left == 160){
                    rect.left = 0;
                }else rect.left += 40;
                sprite.setTextureRect(rect);
                clock.restart();
            }

            window.draw(*world->getBackground());

            window.draw(sprite);

            draw(window);
            gravity();
        }
        window.display();
    }
}

void Engine::draw(sf::RenderWindow& window){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        (*itr)->drawTo(window);
    }
}

void Engine::gravity(){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        if(!ColisionManager::intersectsDown((*itr)->getRect())){
            (*itr)->fall();
        }
    }
}