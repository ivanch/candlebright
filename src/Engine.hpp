#pragma once
#include "includes.hpp"
#include "ColisionManager.hpp"
#include "Menu.hpp"

class Engine {
    private:
        sf::View view;
        sf::RenderWindow window;
    
    public:
        Engine();
        ~Engine();

        sf::View* getView() { return &view; }
        sf::RenderWindow* getWindow() { return &window; }
        void draw(sf::Sprite& _sprite);
        void draw(sf::Sprite* _sprite);
        void draw(sf::RectangleShape& _shape);
        void draw(sf::RectangleShape* _shape);

        const bool isWindowOpen() const { return window.isOpen(); }

        void clearWindow();
        void setView();
        void render();
};
