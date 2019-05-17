#pragma once
#ifndef Intersect
#define Intersect

namespace Intersect{
    /* Parte de baixo do obj1 com a parte de cima do obj2. */
    bool intersectsDown(sf::FloatRect obj1, sf::FloatRect obj2){
        if( obj1.top+obj1.height >= obj2.top &&
            obj1.top+obj1.height < obj2.top+obj2.height &&
            obj1.left+obj1.width > obj2.left &&
            obj1.left < obj2.left+obj2.width ) return true;
        else return false;
    }

    /* Parte de cima do objeto obj1 com a parte de baixo do obj2. */
    bool intersectsUp(sf::FloatRect obj1, sf::FloatRect obj2){
        if( obj1.top <= obj2.top+obj2.height &&
            obj1.top >= obj2.top &&
            obj1.left+obj1.width > obj2.left &&
            obj1.left < obj2.left+obj2.width ) return true;
        else return false;
    }

    /* Lado direito do obj1 com o lado esquerdo do obj2. */
    bool intersectsRight(sf::FloatRect obj1, sf::FloatRect obj2){
        if( obj1.left+obj1.width >= obj2.left &&
            obj1.left+obj1.width < obj2.left+obj2.width &&
            obj1.top+obj1.height > obj2.top &&
            obj1.top < obj2.top+obj2.height ) return true;
        else return false;
    }

    /* Lado esquerdo do obj1 com o lado direito do obj2. */
    bool intersectsLeft(sf::FloatRect obj1, sf::FloatRect obj2){
        if( obj1.left <= obj2.left+obj2.width &&
            obj1.left > obj2.left &&
            obj1.top+obj1.height > obj2.top &&
            obj1.top < obj2.top+obj2.height ) return true;
        else return false;
    }
}
#endif
