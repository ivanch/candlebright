#pragma once
#include "SFML/Graphics/Drawable.hpp"
#include "includes.hpp"

class Engine {
    private:
        sf::View view;
        sf::RenderWindow window;
    
    public:
        Engine();
        ~Engine();

        sf::View* getView() { return &view; }
        sf::RenderWindow* getWindow() { return &window; }
        void draw(const sf::Drawable& drawable);

        const bool isWindowOpen() const { return window.isOpen(); }

        void clearWindow();
        void setView();
        void render();
};
