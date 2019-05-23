#pragma once
#include "includes.hpp"
#include "Listener.hpp"
#include "Engine.hpp"
#include "Character.hpp"
#include "Object.hpp"

class Enemy: private Listener, public Object, public Character {

    public:
    static vector<Enemy*> enemies;

    Enemy(sf::Vector2f pos = {500,0}, string _name = "");
    ~Enemy();
    void setPos(sf::Vector2f newPos);
    void drawTo(sf::RenderWindow &window);
    sf::FloatRect getRect();
    void setWorld(World* _world){ world = _world; }
    void move(sf::Vector2f vec);
    void onUpdate();
    void fall();
    sf::Vector2f getPos();
    void takeDamage(float damage);


    protected:

    private:
    sf::RectangleShape enemy;
    sf::Vector2f RespawnPos;
    string name;
    World* world;
};
