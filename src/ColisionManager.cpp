#include "ColisionManager.hpp"

/* Verfica se algum Objeto intersecta com a parte de baixo do obj1 */
bool ColisionManager::intersectsDownCharacter(sf::FloatRect obj){
    for(auto itr = Character::characters.begin(); itr != Character::characters.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj) continue;
        if(Intersect::intersectsDown(obj,p_rect)) return true;
    }
    return false;
}
/* Verfica se algum Objeto intersecta com a parte de cima do obj1 */
bool ColisionManager::intersectsUpCharacter(sf::FloatRect obj1){
    for(auto itr = Character::characters.begin(); itr != Character::characters.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsUp(obj1,p_rect)) return true;
    }
    return false;
}

/* Verfica se algum Objeto intersecta com a parte direita do obj1 */
bool ColisionManager::intersectsRightCharacter(sf::FloatRect obj1){
    for(auto itr = Character::characters.begin(); itr != Character::characters.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsRight(obj1,p_rect)) return true;
    }
    return false;
}

/* Verfica se algum Objeto intersecta com a parte esquerda do obj1 */
bool ColisionManager::intersectsLeftCharacter(sf::FloatRect obj1){
    for(auto itr = Character::characters.begin(); itr != Character::characters.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsLeft(obj1,p_rect)) return true;
    }
    return false;
}

/* Move as personagens que estão em cima de algum Objeto */
void ColisionManager::moveChars(Object* obj, sf::Vector2f _move){
    for(auto itr = Character::characters.begin(); itr != Character::characters.end(); ++itr){
        if(Intersect::intersectsUp(obj->getRect(), (*itr)->getRect())){
            (*itr)->move(_move);
        }
    }
}
/* Verfica se algum Objeto intersecta com a parte de baixo do obj1 */
bool ColisionManager::intersectsDownObject(sf::FloatRect obj){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj) continue;
        if(Intersect::intersectsDown(obj,p_rect)) return true;
    }
    return false;
}
/* Verfica se algum Objeto intersecta com a parte de cima do obj1 */
bool ColisionManager::intersectsUpObject(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsUp(obj1,p_rect)) return true;
    }
    return false;
}

/* Verfica se algum Objeto intersecta com a parte direita do obj1 */
bool ColisionManager::intersectsRightObject(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsRight(obj1,p_rect)) return true;
    }
    return false;
}

/* Verfica se algum Objeto intersecta com a parte esquerda do obj1 */
bool ColisionManager::intersectsLeftObject(sf::FloatRect obj1){
    for(auto itr = Object::objects.begin(); itr != Object::objects.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsLeft(obj1,p_rect)) return true;
    }
    return false;
}
