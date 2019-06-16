#include "IdleState.hpp"

IdleState::IdleState(): CharacterState(STATE_IDLE){

}

IdleState::~IdleState(){

}

void IdleState::jumping(Character* _char){
    _char->setState(STATE_JUMPING);
}

void IdleState::walking(Character* _char){
    _char->setState(STATE_WALKING);
}

void IdleState::falling(Character* _char){
    _char->setState(STATE_FALLING);
}

void IdleState::attacking(Character* _char){
    _char->setState(STATE_ATTACKING);
}