#include "Engine.hpp"

Engine::Engine(): view(sf::FloatRect(0.f, 300.f, 600.f, 500.f)) {
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 350);
    window.create(sf::VideoMode(600, 400), "Joguinho!", sf::Style::Titlebar | sf::Style::Close);
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
