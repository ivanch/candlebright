#include "WalkingState.hpp"

WalkingState::WalkingState(): CharacterState(STATE_WALKING){

}

WalkingState::~WalkingState(){

}

bool WalkingState::idle(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}

bool WalkingState::jumping(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new JumpingState());
    return true;
}

bool WalkingState::falling(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}

bool WalkingState::attacking(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new AttackingState());
    return true;
}