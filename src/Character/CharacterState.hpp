#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Character;

class CharacterState {    
    public:
        enum State {
            STATE_IDLE,         //  0
            STATE_WALKING,      //  1
            STATE_JUMPING,      //  2
            STATE_FALLING,      //  3
            STATE_ATTACKING     //  4
        };

        CharacterState(State _state);
        virtual ~CharacterState();

        virtual bool idle(Character* _char);
        virtual bool walking(Character* _char);
        virtual bool jumping(Character* _char);
        virtual bool falling(Character* _char);
        virtual bool attacking(Character* _char);

        State getState(){ return state; }
    
    private:
        State state;
};