#include "IdleState.hpp"

IdleState::IdleState(): CharacterState(STATE_IDLE){

}

IdleState::~IdleState(){

}

const bool IdleState::idle(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}

const bool IdleState::jumping(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new JumpingState());
    return true;
}

const bool IdleState::walking(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new WalkingState());
    return true;
}

const bool IdleState::falling(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}

const bool IdleState::attacking(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new AttackingState());
    return true;
}