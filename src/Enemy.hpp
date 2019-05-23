#pragma once
#include "includes.hpp"
#include "Listener.hpp"
#include "World.hpp"
#include "Character.hpp"

class Enemy: private Listener, public Object, public Character {

    public:
    Enemy(sf::View& _view, string _name = "");
        ~Enemy(){};
    void setPos(sf::Vector2f newPos);
    void drawTo(sf::RenderWindow &window);
    sf::FloatRect getRect();
    void setWorld(World* _world){ world = _world; }
    void debug();
    void move(sf::Vector2f vec);
    void moveRight();
    void moveLeft();
    void onUpdate();
    void fall();


    protected:

    private:
    sf::RectangleShape enemy;
    sf::View& view;
    sf::Vector2f RespawnPos;
    string name;
    World* world;
    bool mRight;
    bool mLeft;
    sf::Vector2f originalPos;
    sf::Vector2f moving;


};
