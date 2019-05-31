#include "ColisionManager.hpp"

/* Verfica se algum Objeto intersecta com a parte de baixo do obj1 */
bool ColisionManager::intersectsDown(sf::FloatRect obj){
    for(auto itr = Entity::entities.begin(); itr != Entity::entities.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj) continue;
        if(Intersect::intersectsDown(obj,p_rect)) return true;
    }
    return false;
}
/* Verfica se algum Objeto intersecta com a parte de cima do obj1 */
bool ColisionManager::intersectsUp(sf::FloatRect obj1){
    for(auto itr = Entity::entities.begin(); itr != Entity::entities.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsUp(obj1,p_rect)) return true;
    }
    return false;
}

/* Verfica se algum Objeto intersecta com a parte direita do obj1 */
bool ColisionManager::intersectsRight(sf::FloatRect obj1){
    for(auto itr = Entity::entities.begin(); itr != Entity::entities.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsRight(obj1,p_rect)) return true;
    }
    return false;
}

/* Verfica se algum Objeto intersecta com a parte esquerda do obj1 */
bool ColisionManager::intersectsLeft(sf::FloatRect obj1){
    for(auto itr = Entity::entities.begin(); itr != Entity::entities.end(); ++itr){
        sf::FloatRect p_rect = (*itr)->getRect();
        if(p_rect == obj1) continue;
        if(Intersect::intersectsLeft(obj1,p_rect)) return true;
    }
    return false;
}

/* Move as personagens que estão em cima de algum Objeto */
void ColisionManager::moveChars(Entity* obj, sf::Vector2f _move){
    ////////////////////////////////////////////////
    /*  REFAZER QUANDO TIVER A LISTA DE ENTIDADES */
    ////////////////////////////////////////////////
    /*
    for(auto itr = Character::characters.begin(); itr != Character::characters.end(); ++itr){
        if(Intersect::intersectsUp(obj->getRect(), (*itr)->getRect())){
            (*itr)->move(_move);
        }
    }
    */
}