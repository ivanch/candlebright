#include "AttackingState.hpp"

AttackingState::AttackingState(): CharacterState(STATE_ATTACKING){

}

AttackingState::~AttackingState(){

}

const bool AttackingState::idle(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}

const bool AttackingState::falling(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}