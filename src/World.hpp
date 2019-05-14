#pragma once
#include "includes.hpp"
#include "Plataform.hpp"
#include "Object.hpp"
#include "Build.hpp"

class World{
    private:
        vector<Plataform> plataforms;
        vector<Build*> builds;
        vector<Object*> objects;

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
        bool intersectsDown(sf::FloatRect player);
        bool intersectsDown(sf::FloatRect player, sf::FloatRect plataform);
        bool intersectsUp(sf::FloatRect player);
        bool intersectsUp(sf::FloatRect player, sf::FloatRect plataform);
        bool intersectsRight(sf::FloatRect player);
        bool intersectsRight(sf::FloatRect player, sf::FloatRect plataform);
        bool intersectsLeft(sf::FloatRect player);
        bool intersectsLeft(sf::FloatRect player, sf::FloatRect plataform);
};
