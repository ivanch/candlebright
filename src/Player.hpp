#pragma once
#include "includes.hpp"
#include "Listener.hpp"
#include "World.hpp"
#include "Character.hpp"

class Player: public Listener, public Object, public Character {
    private:
        sf::RectangleShape player;
        sf::View& view;
        sf::Vector2f RespawnPos;
        string name;
        Character info;
        World* world;

        void move(sf::Vector2f vec);
    public:
        Player(sf::View& _view, string _name = "");
        ~Player();

        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();
        void jump();
        void onUpdate();
        void drawTo(sf::RenderWindow &window);
        void fall();
        sf::FloatRect getRect();

        void setWorld(World* _world){ world = _world; }
};
