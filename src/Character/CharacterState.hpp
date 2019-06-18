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

        static string getStateName(State _state){
            switch (_state){
                case STATE_IDLE:
                    return "Idle";
                case STATE_WALKING:
                    return "Walking";
                case STATE_FALLING:
                    return "Falling";
                case STATE_JUMPING:
                    return "Jumping";
                case STATE_ATTACKING:
                    return "Attacking";            
                default:
                    return "NULL";
            }
        }
        
    private:
        State state;
};