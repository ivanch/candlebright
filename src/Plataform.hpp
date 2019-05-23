#pragma once
#include "includes.hpp"
#include "Object.hpp"
#include "Listener.hpp"
#include "Character.hpp"
#include "utils.hpp"

class Plataform : public Object, private Listener{
    private:
        sf::RectangleShape rect;
        sf::Color color;
        sf::Texture* texture;

        bool moving;
        sf::Vector2f vel;
        sf::Vector2f move;
        sf::Vector2f moveActual;
        const sf::Vector2f originalPos;
        bool mRight, mUp;
        void fmove();
        void moveChars(sf::Vector2f _move);

    public:
        static vector<Plataform*> plataforms;
        Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col = sf::Color::White);
        Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex);
        ~Plataform();

        void drawTo(sf::RenderWindow& window);
        void onUpdate();
        void setMoveSpeed(sf::Vector2f _vel);
        void setMove(sf::Vector2f _move);
        void setMoving(bool _moving);
        sf::FloatRect getRect();

};
