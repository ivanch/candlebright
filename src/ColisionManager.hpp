#pragma once
#include "includes.hpp"
#include "Character.hpp"
#include "utils.hpp"

class ColisionManager {
    public:
        ColisionManager();
        ~ColisionManager();

        static bool intersectsDown(sf::FloatRect obj1); // Verifica se a parte de baixo do obj1 intersecta com algum outro objeto na parte de cima
        static bool intersectsUp(sf::FloatRect obj1);
        static bool intersectsRight(sf::FloatRect obj1);
        static bool intersectsLeft(sf::FloatRect obj1);
        static void moveChars(Entity* obj, sf::Vector2f _move);

};