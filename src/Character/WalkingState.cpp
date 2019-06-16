#include "WalkingState.hpp"

WalkingState::WalkingState(): CharacterState(STATE_WALKING){

}

WalkingState::~WalkingState(){

}

void WalkingState::jumping(Character* _char){
    _char->setState(STATE_JUMPING);
}

void WalkingState::falling(Character* _char){
    _char->setState(STATE_FALLING);
}

void WalkingState::attacking(Character* _char){
    _char->setState(STATE_ATTACKING);
}