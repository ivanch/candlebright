#include "World.hpp"
#include "TextureManager.hpp"

World::World(){
    addPlataform({0,700,1280,720}, TextureManager::grass);
    addPlataform({200,650,1280,660});
    addPlataform({250,580,1280,590}, sf::Color::Red);

    addBuild({10,50},{100,650}, sf::Color::Cyan);
    addBuild({20,50},{50,500}, sf::Color::Cyan);
    addBuild({20,50},{125,500}, sf::Color::Cyan);
}
World::~World(){}

void World::addPlataform(sf::FloatRect rect){
    addPlataform(rect, sf::Color::White);
}
void World::addPlataform(sf::FloatRect rect, sf::Color color){
    Plataform p1({rect.left, rect.top, rect.width-rect.left, rect.height-rect.top}, color);
    plataforms.push_back(p1);
}
void World::addPlataform(sf::FloatRect rect, sf::Texture* texture){
    Plataform p1({rect.left, rect.top, rect.width-rect.left, rect.height-rect.top}, texture);
    plataforms.push_back(p1);
}

void World::addBuild(sf::Vector2f size, sf::Vector2f pos){
    addBuild(size,pos,sf::Color::White);
}
void World::addBuild(sf::Vector2f size, sf::Vector2f pos, sf::Color color){
    Build b1(size,pos,color);
    builds.push_back(b1);
}
void World::addBuild(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture){
    Build b1(size,pos,texture);
    builds.push_back(b1);
}

void World::draw(sf::RenderWindow& window){
    for(auto itr = plataforms.begin(); itr != plataforms.end(); ++itr){
        itr->draw(window);
    }
    for(auto itr = builds.begin(); itr != builds.end(); ++itr){
        itr->draw(window);
    }
}

void World::addObject(Object* o){
    objects.push_back(o);
}

void World::gravity(){
    for(auto itr = objects.begin(); itr != objects.end(); ++itr){
        if(!isColliding((*itr)->getRect())){
            (*itr)->fall();
        }
    }
}

bool World::isColliding(sf::FloatRect rect){
    for(auto itr = plataforms.begin(); itr != plataforms.end(); ++itr){
        sf::FloatRect p_rect = itr->getRect();
        // Debug
        /*
        cout << "Player: " << rect.left << ", " << rect.top << ", " << rect.width << ", " << rect.height << endl;
        cout << "Plataforma: " << p_rect.left << ", " << p_rect.top << ", " << p_rect.width << ", " << p_rect.height << endl;
        cout << intersectsDown(rect,p_rect) << endl;
        */
        if(intersectsDown(rect,p_rect)) return true;
    }
    for(auto itr = builds.begin(); itr != builds.end(); ++itr){
        sf::FloatRect p_rect = itr->getRect();
        if(intersectsDown(rect,p_rect)) return true;
    }
    return false;
}

bool World::intersectsDown(sf::FloatRect player, sf::FloatRect obj){
    if( player.top+player.height == obj.top &&
        player.left+player.width > obj.left &&
        player.left < obj.left+obj.width ) return true;
    else return false;
}

bool World::intersectsUp(sf::FloatRect player){
    for(auto itr = plataforms.begin(); itr != plataforms.end(); ++itr){
        sf::FloatRect p_rect = itr->getRect();
        if(intersectsUp(player,p_rect)) return true;
    }
    return false;
}

bool World::intersectsUp(sf::FloatRect player, sf::FloatRect plataform){
    if( player.top == plataform.top+plataform.height &&
        player.left+player.width > plataform.left &&
        player.left < plataform.left+plataform.width ) return true;
    else return false;
}

bool World::intersectsRight(sf::FloatRect player){
    for(auto itr = builds.begin(); itr != builds.end(); ++itr){
        sf::FloatRect p_rect = itr->getRect();
        if(intersectsRight(player,p_rect)) return true;
    }
    return false;
}
bool World::intersectsRight(sf::FloatRect player, sf::FloatRect obj){
    if( player.left+player.width >= obj.left &&
        player.left+player.width <= obj.left+obj.width &&
        player.top+player.height > obj.top &&
        player.top < obj.top+obj.height ) return true;
    else return false;
}

bool World::intersectsLeft(sf::FloatRect player){
    for(auto itr = builds.begin(); itr != builds.end(); ++itr){
        sf::FloatRect p_rect = itr->getRect();
        if(intersectsLeft(player,p_rect)) return true;
    }
    return false;
}
bool World::intersectsLeft(sf::FloatRect player, sf::FloatRect obj){
    if( player.left <= obj.left+obj.width &&
        player.left >= obj.left &&
        player.top+player.height > obj.top &&
        player.top < obj.top+obj.height ) return true;
    else return false;
}