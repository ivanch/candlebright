#include "World.hpp"
#include "TextureManager.hpp"
#include "Object.hpp"

World::World(){
    new Plataform({1280,30},{0,720}, TextureManager::grass); // Chão
    new Plataform({1280,10},{150,650}); // Plataforma branca
    Plataform* p = new Plataform({1280,5},{200,580}, sf::Color::Red); // Plataforma vermelha
    p->setMoving(true);
    p->setMove({100,0});
    p->setMoveSpeed({0.1,0});
    
    p = new Plataform({25,2},{-25,700}, sf::Color::Magenta); // Plataforma vermelha
    p->setMoving(true);
    p->setMove({0,100});
    p->setMoveSpeed({0,0.1});

    new Build({10,50},{100,650}, sf::Color::Cyan);
    new Build({20,50},{50,500}, sf::Color::Cyan);
    new Build({20,50},{125,500}, sf::Color::Cyan);
}
World::~World(){}

void World::draw(sf::RenderWindow& window){
    for(auto itr = Plataform::plataforms.begin(); itr != Plataform::plataforms.end(); ++itr){
        (*itr)->drawTo(window);
    }
    for(auto itr = Build::builds.begin(); itr != Build::builds.end(); ++itr){
        (*itr)->drawTo(window);
    }
}

void World::gravity(){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        if(!intersectsDown((*itr)->getRect())){
            (*itr)->fall();
        }
    }
}

bool World::intersectsDown(sf::FloatRect obj){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj) continue;
        if(Intersects::intersectsDown(obj,p_rect)) return true;
    }
    return false;
}
bool World::intersectsUp(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersects::intersectsUp(obj1,p_rect)) return true;
    }
    return false;
}

bool World::intersectsRight(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersects::intersectsRight(obj1,p_rect)) return true;
    }
    return false;
}

bool World::intersectsLeft(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersects::intersectsLeft(obj1,p_rect)) return true;
    }
    return false;
}