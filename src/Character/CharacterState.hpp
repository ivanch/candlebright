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

        virtual const bool idle(Character* _char);
        virtual const bool walking(Character* _char);
        virtual const bool jumping(Character* _char);
        virtual const bool falling(Character* _char);
        virtual const bool attacking(Character* _char);

        const State getState() const { return state; }
    
    private:
        State state;
};