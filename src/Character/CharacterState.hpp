#pragma once

#include "../includes.hpp"

class Character;

class CharacterState {    
    public:
        enum State {
            STATE_IDLE,
            STATE_WALKING,
            STATE_JUMPING,
            STATE_FALLING,
            STATE_ATTACKING
        };

        CharacterState(State _state);
        virtual ~CharacterState();

        virtual void idle(Character* _char);
        virtual void walking(Character* _char);
        virtual void jumping(Character* _char);
        virtual void falling(Character* _char);
        virtual void attacking(Character* _char);

        State getState(){ return state; }
    
    private:
        State state;
};