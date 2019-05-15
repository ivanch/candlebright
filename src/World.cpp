#include "World.hpp"
#include "TextureManager.hpp"
#include "Object.hpp"

World::World(){
    new Plataform({1280,30},{0,720}, TextureManager::grass);
    new Plataform({1280,10},{150,650});
    new Plataform({1280,5},{200,580}, sf::Color::Red);

    new Build({10,50},{100,650}, sf::Color::Cyan);
    new Build({20,50},{50,500}, sf::Color::Cyan);
    new Build({20,50},{125,500}, sf::Color::Cyan);
}
World::~World(){}

void World::draw(sf::RenderWindow& window){
    for(auto itr = Plataform::plataforms.begin(); itr != Plataform::plataforms.end(); ++itr){
        (*itr)->draw(window);
    }
    for(auto itr = Build::builds.begin(); itr != Build::builds.end(); ++itr){
        (*itr)->draw(window);
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
        if(intersectsDown(obj,p_rect)) return true;
    }
    return false;
}
bool World::intersectsDown(sf::FloatRect obj1, sf::FloatRect obj2){
    if( obj1.top+obj1.height >= obj2.top &&
        obj1.top+obj1.height <= obj2.top+obj2.height &&
        obj1.left+obj1.width > obj2.left &&
        obj1.left < obj2.left+obj2.width ) return true;
    else return false;
}

bool World::intersectsUp(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(intersectsUp(obj1,p_rect)) return true;
    }
    return false;
}
bool World::intersectsUp(sf::FloatRect obj1, sf::FloatRect obj2){
    if( obj1.top == obj2.top+obj2.height &&
        obj1.left+obj1.width > obj2.left &&
        obj1.left < obj2.left+obj2.width ) return true;
    else return false;
}

bool World::intersectsRight(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(intersectsRight(obj1,p_rect)) return true;
    }
    return false;
}
bool World::intersectsRight(sf::FloatRect obj1, sf::FloatRect obj2){
    if( obj1.left+obj1.width >= obj2.left &&
        obj1.left+obj1.width <= obj2.left+obj2.width &&
        obj1.top+obj1.height > obj2.top &&
        obj1.top < obj2.top+obj2.height ) return true;
    else return false;
}

bool World::intersectsLeft(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(intersectsLeft(obj1,p_rect)) return true;
    }
    return false;
}
bool World::intersectsLeft(sf::FloatRect obj1, sf::FloatRect obj2){
    if( obj1.left <= obj2.left+obj2.width &&
        obj1.left >= obj2.left &&
        obj1.top+obj1.height > obj2.top &&
        obj1.top < obj2.top+obj2.height ) return true;
    else return false;
}