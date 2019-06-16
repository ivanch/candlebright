#include "AttackingState.hpp"

AttackingState::AttackingState(): CharacterState(STATE_ATTACKING){

}

AttackingState::~AttackingState(){

}

void AttackingState::idle(Character* _char){
    _char->setState(STATE_IDLE);
}

void AttackingState::falling(Character* _char){
    _char->setState(STATE_FALLING);
}