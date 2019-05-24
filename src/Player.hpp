#pragma once
#include "includes.hpp"
#include "Listener.hpp"
//#include "World.hpp"
#include "Engine.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

class Player : private Listener, public Object, public Character {
    private:
        sf::View& view;
        sf::Vector2f RespawnPos;
        string name;
        //Character info;
        sf::Texture pTexture;
        sf::Sprite pSprite;

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
        void attack();



        void debug();
};
