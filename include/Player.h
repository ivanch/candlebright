#pragma once
#include "includes.h"
#include "Listener.h"
class Player: public Listener{
    private:
        string name;
        int score;
        float moveSpeed;
        bool isJumping;
        float jumpHeight;
        float groundHeight;
        float maxVelocityX;
        float maxVelocityY;
        sf::Vector2f acc; // vetor de aceleração

        sf::RectangleShape player;
        sf::View& view;

        void move(sf::Vector2f vec);
    public:
        Player(sf::View& _view, float ground = 0, string _name = "");
        ~Player();

        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();
        void jump();
        void jumpFall();
        void onUpdate();
        void drawTo(sf::RenderWindow &window);
};
