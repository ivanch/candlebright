#include "World.hpp"
#include "TextureManager.hpp"

World::World(){
    new Plataform({1280,30},{0,720}, TextureManager::grass); // Chão
    new Plataform({1280,10},{150,650}); // Plataforma branca
    Plataform* p = new Plataform({1280,5},{200,580}, sf::Color::Red); // Plataforma vermelha
    p->setMoving(true);
    p->setMove({100,0});
    p->setMoveSpeed({0.5,0});

    p = new Plataform({25,2},{-25,700}, sf::Color::Magenta); // Plataforma rosa
    p->setMoving(true);
    p->setMove({0,100});
    p->setMoveSpeed({0,0.5});

    new Build({10,50},{100,650}, sf::Color::Cyan);
    new Build({20,50},{50,500}, sf::Color::Cyan);
    new Build({20,50},{125,500}, sf::Color::Cyan);
}
World::~World(){}
