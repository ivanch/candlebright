#include "World.hpp"
#include "TextureManager.hpp"

World::World(){
    Plataform* p;
    new Plataform({1280,30},{0,720}, TextureManager::grass); // Chão
    new Plataform({1280,10},{150,625}); // Plataforma branca
    p = new Plataform({1280,5},{200,550}, sf::Color::Red); // Plataforma vermelha
    p->setMoving(true);
    p->setMove({100,0});
    p->setMoveSpeed({0.5,0});

    p = new Plataform({50,2},{-50,700}, sf::Color::Magenta); // Plataforma rosa
    p->setMoving(true);
    p->setMove({0,100});
    p->setMoveSpeed({0,0.5});

    new Build({10,50},{100,650}, sf::Color::Cyan);
    new Build({20,50},{50,500}, sf::Color::Cyan);
    new Build({20,50},{125,500}, sf::Color::Cyan);
}
World::~World(){}
