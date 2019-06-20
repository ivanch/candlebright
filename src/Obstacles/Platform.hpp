#pragma once
#include "../includes.hpp"
#include "Obstacle.hpp"
#include "../System/Engine.hpp"

class Platform : public Obstacle {
    private:
        sf::RectangleShape rect;
        sf::Color color;
        sf::Texture* texture;
        sf::Sprite* sprite;

        bool moving;
        sf::Vector2f vel;
        sf::Vector2f move;
        sf::Vector2f moveActual;
        const sf::Vector2f originalPos;
        bool mRight, mUp;
        void fmove();

    public:
        Platform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col = sf::Color::White);
        Platform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex);
        Platform(sf::Vector2f size, sf::Vector2f pos, sf::Sprite* _spr);
        ~Platform();

        void setMoveSpeed(sf::Vector2f _vel);
        void setMove(sf::Vector2f _move);
        void setMoving(bool _moving);
        virtual sf::FloatRect getRect();
        virtual void draw(Engine* engine);
        virtual void update();

        virtual float getDamage(){ return 0; }
        virtual sf::Vector2f getPos(){ return rect.getPosition(); }

};
