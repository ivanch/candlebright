#pragma once
#include "includes.hpp"
#include "Entity.hpp"

class Thing : public Entity {
    protected:
        bool collidingUp;
        bool collidingRight;
        bool collidingLeft;
        bool collidingDown;
    
    public:
        Thing() {
            collidingUp = false;
            collidingRight = false;
            collidingLeft = false;
            collidingDown = false;
        }
        ~Thing() { }
        virtual void fall(){}
        virtual sf::FloatRect getRect(){ return {0,0,0,0}; }

        void setCollidingUp(bool _isColliding){ collidingUp = _isColliding; }
        void setCollidingRight(bool _isColliding){ collidingRight = _isColliding; }
        void setCollidingLeft(bool _isColliding){ collidingLeft = _isColliding; }
        void setCollidingDown(bool _isColliding){ collidingDown = _isColliding; }
        
        bool isCollidingUp(){ return collidingUp; }
        bool isCollidingRight(){ return collidingRight; }
        bool isCollidingLeft(){ return collidingLeft; }
        bool isCollidingDown(){ return collidingDown; }
};