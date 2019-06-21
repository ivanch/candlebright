#include "CollisionManager.hpp"

CollisionManager::CollisionManager(ThingsList* _things){
    things = _things;
}

void CollisionManager::checkCollisions(){
    for(auto itr = things->begin(); itr != things->end(); ++itr){
        Thing* obj1 = *itr;
        obj1->setCollidingUp(false);
        obj1->setCollidingRight(false);
        obj1->setCollidingLeft(false);
        obj1->setCollidingDown(false);
    }
    for(auto itr1 = things->begin(); itr1 != things->end(); ++itr1){
        Thing* obj1 = *itr1;
        for(auto itr2 = itr1; itr2 != things->end(); ++itr2){
            Thing* obj2 = *itr2;
            if(obj1 == obj2) continue;
            if(intersectsUp(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingUp(true);
                obj2->setCollidingDown(true);
            }else if(intersectsDown(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingDown(true);
                obj2->setCollidingUp(true);
            }
            if(intersectsRight(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingRight(true);
                obj2->setCollidingLeft(true);
            }else if(intersectsLeft(obj1->getRect(), obj2->getRect())){
                obj1->setCollidingLeft(true);
                obj2->setCollidingRight(true);
            }
        }
    }
}

/* Parte de baixo do obj1 com a parte de cima do obj2. */
bool CollisionManager::intersectsDown(sf::FloatRect obj1, sf::FloatRect obj2){
    if( obj1.top+obj1.height >= obj2.top &&
        obj1.top+obj1.height <= obj2.top+LIMIT &&
        obj1.top+obj1.height < obj2.top+obj2.height &&
        obj1.left+obj1.width > obj2.left &&
        obj1.left < obj2.left+obj2.width ) return true;
    else return false;
}

/* Parte de cima do objeto obj1 com a parte de baixo do obj2. */
bool CollisionManager::intersectsUp(sf::FloatRect obj1, sf::FloatRect obj2){
    if( obj1.top <= obj2.top+obj2.height &&
        obj1.top >= obj2.top+obj2.height-LIMIT &&
        obj1.top >= obj2.top &&
        obj1.left+obj1.width > obj2.left &&
        obj1.left < obj2.left+obj2.width ) return true;
    else return false;
}

/* Lado direito do obj1 com o lado esquerdo do obj2. */
bool CollisionManager::intersectsRight(sf::FloatRect obj1, sf::FloatRect obj2){
    if( obj1.left+obj1.width >= obj2.left &&
        obj1.left+obj1.width <= obj2.left+LIMIT &&
        obj1.left+obj1.width < obj2.left+obj2.width &&
        obj1.top+obj1.height > obj2.top &&
        obj1.top < obj2.top+obj2.height ) return true;
    else return false;
}

/* Lado esquerdo do obj1 com o lado direito do obj2. */
bool CollisionManager::intersectsLeft(sf::FloatRect obj1, sf::FloatRect obj2){
    if( obj1.left <= obj2.left+obj2.width &&
        obj1.left >= obj2.left+obj2.width-LIMIT &&
        obj1.left > obj2.left &&
        obj1.top+obj1.height > obj2.top &&
        obj1.top < obj2.top+obj2.height ) return true;
    else return false;
}