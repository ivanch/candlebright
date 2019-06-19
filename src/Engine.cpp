#include "Engine.hpp"

Engine::Engine(){
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 350);
    window.create(sf::VideoMode(600, 400), "Candlebright: Ominous Whip", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);
}
Engine::~Engine(){}

void Engine::draw(const sf::Drawable& drawable){
    window.draw(drawable);
}

void Engine::clearWindow(){
    window.clear();
}

void Engine::render(){
    window.display();
}
