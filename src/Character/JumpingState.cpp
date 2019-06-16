#include "JumpingState.hpp"

JumpingState::JumpingState(): CharacterState(STATE_JUMPING){

}

JumpingState::~JumpingState(){

}

void JumpingState::falling(Character* _char){
    _char->setState(STATE_FALLING);
}