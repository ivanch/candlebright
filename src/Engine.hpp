#pragma once
#include "includes.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Menu.hpp"

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

        static bool intersectsDown(sf::FloatRect obj1); // Verifica se a parte de baixo do obj1 intersecta com algum outro objeto na parte de cima
        static bool intersectsUp(sf::FloatRect obj1);
        static bool intersectsRight(sf::FloatRect obj1);
        static bool intersectsLeft(sf::FloatRect obj1);
};
