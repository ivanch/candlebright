#pragma once
#include "includes.hpp"
#include "Listener.hpp"
#include "World.hpp"
#include "Character.hpp"

class Player: private Listener, public Object, public Character {
    private:
        sf::RectangleShape player;
        sf::View& view;
        sf::Vector2f RespawnPos;
        string name;
        //Character info;
        World* world;

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
        void move(sf::Vector2f vec);

        void setWorld(World* _world){ world = _world; }

        void debug();
};
