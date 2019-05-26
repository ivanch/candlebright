#pragma once
#include "includes.hpp"
#include "World.hpp"
#include "Menu.hpp"
#include "Listener.hpp"
#include "ColisionManager.hpp"

class Engine{
    private:
        sf::RenderWindow& window;
        sf::View& view;

        World* world;


        Menu menu;
        bool menuEnabled;
    public:
        Engine(sf::RenderWindow& _win,  sf::View& _view);
        ~Engine();
        void update();

        const sf::View& getView() const{ return view; }
        const sf::RenderWindow& getWindow() const{ return window; }

        void setWorld(World* _world){ world = _world; }

        void draw(sf::RenderWindow& window);
        void addObject(Object* o);
        void gravity();
};
