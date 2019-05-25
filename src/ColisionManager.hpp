#pragma once
#include "includes.hpp"
#include "Character.hpp"
#include "utils.hpp"

class ColisionManager{
    private:

    public:
        ColisionManager();
        ~ColisionManager();

        static bool intersectsDownCharacter(sf::FloatRect obj1); // Verifica se a parte de baixo do obj1 intersecta com algum outro objeto na parte de cima
        static bool intersectsUpCharacter(sf::FloatRect obj1);
        static bool intersectsRightCharacter(sf::FloatRect obj1);
        static bool intersectsLeftCharacter(sf::FloatRect obj1);
        static bool intersectsDownObject(sf::FloatRect obj1); // Verifica se a parte de baixo do obj1 intersecta com algum outro objeto na parte de cima
        static bool intersectsUpObject(sf::FloatRect obj1);
        static bool intersectsRightObject(sf::FloatRect obj1);
        static bool intersectsLeftObject(sf::FloatRect obj1);
        static void moveChars(Object* obj, sf::Vector2f _move);

};
