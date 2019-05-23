#include "Engine.hpp"
#include "Listener.hpp"

Engine::Engine(sf::RenderWindow& _win,  sf::View& _view):
    window(_win), view(_view), world(NULL), menu(window.getSize().x,window.getSize().y){
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 350);
    window.create(sf::VideoMode(600, 400), "Joguinho!", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);
    menuEnabled = false;
}
Engine::~Engine(){}

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

            //for(auto itr = sprites.begin(); itr != sprites.end(); ++itr){
            //    window.draw(*(*itr));
            //}
            window.draw(*world->getBackground());

            draw(window);
            gravity();

            for(auto itr = Listener::listeners.begin(); itr != Listener::listeners.end(); ++itr){
                (*itr)->onUpdate();
                (*itr)->drawTo(window);
            }
        }
        window.display();
    }
}

void Engine::draw(sf::RenderWindow& window){
    for(auto itr = Plataform::plataforms.begin(); itr != Plataform::plataforms.end(); ++itr){
        (*itr)->drawTo(window);
    }
    for(auto itr = Build::builds.begin(); itr != Build::builds.end(); ++itr){
        (*itr)->drawTo(window);
    }
}

void Engine::gravity(){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        if(!intersectsDown((*itr)->getRect())){
            (*itr)->fall();
        }
    }
}

/* Verfica se algum objeto intersecta com a parte de baixo do obj1 */
bool Engine::intersectsDown(sf::FloatRect obj){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj) continue;
        if(Intersect::intersectsDown(obj,p_rect)) return true;
    }
    return false;
}
/* Verfica se algum objeto intersecta com a parte de cima do obj1 */
bool Engine::intersectsUp(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsUp(obj1,p_rect)) return true;
    }
    return false;
}

/* Verfica se algum objeto intersecta com a parte direita do obj1 */
bool Engine::intersectsRight(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsRight(obj1,p_rect)) return true;
    }
    return false;
}

/* Verfica se algum objeto intersecta com a parte esquerda do obj1 */
bool Engine::intersectsLeft(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsLeft(obj1,p_rect)) return true;
    }
    return false;
}
