#pragma once
#include "includes.hpp"
#include "Plataform.hpp"
#include "Object.hpp"
#include "Build.hpp"

class World{
    private:

    public:
        World();
        ~World();

        void draw(sf::RenderWindow& window);
        void addObject(Object* o);
        void gravity();

        bool intersectsDown(sf::FloatRect obj1); // Verifica se a parte de baixo do obj1 intersecta com algum outro objeto na parte de cima
        bool intersectsUp(sf::FloatRect obj1);
        bool intersectsRight(sf::FloatRect obj1);
        bool intersectsLeft(sf::FloatRect obj1);
};
