#include "IdleState.hpp"

IdleState::IdleState(): CharacterState(STATE_IDLE){

}

IdleState::~IdleState(){

}

bool IdleState::jumping(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new JumpingState());
    return true;
}

bool IdleState::walking(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new WalkingState());
    return true;
}

bool IdleState::falling(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}

bool IdleState::attacking(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new AttackingState());
    return true;
}