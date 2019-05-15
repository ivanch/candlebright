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

        void addPlataform(sf::FloatRect rect);
        void addPlataform(sf::FloatRect rect, sf::Color);
        void addPlataform(sf::FloatRect rect, sf::Texture* texture);

        void addBuild(sf::Vector2f size, sf::Vector2f pos);
        void addBuild(sf::Vector2f size, sf::Vector2f pos, sf::Color);
        void addBuild(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture);
        void addBuild(sf::FloatRect rect, sf::Texture* texture);
        void addBuild(sf::FloatRect rect, sf::Color);

        bool intersectsDown(sf::FloatRect obj1); // Verifica se o obj1 intersecta com algum outro objeto na parte de baixo do obj1
        bool intersectsDown(sf::FloatRect obj1, sf::FloatRect obj2); // Verifica se o obj1 intersecta com o obj2. Parte de baixo do obj1 com a parte de cima do obj2.
        bool intersectsUp(sf::FloatRect obj1);
        bool intersectsUp(sf::FloatRect obj1, sf::FloatRect obj2); // Parte de cima do objeto obj1 com a parte de baixo do obj2.
        bool intersectsRight(sf::FloatRect obj1);
        bool intersectsRight(sf::FloatRect obj1, sf::FloatRect obj2); // Lado direito do obj1 com o lado esquerdo do obj2.
        bool intersectsLeft(sf::FloatRect obj1);
        bool intersectsLeft(sf::FloatRect obj1, sf::FloatRect obj2); // Lado esquerdo do obj1 com o lado direito do obj2.
};
