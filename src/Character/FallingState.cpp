#include "FallingState.hpp"

FallingState::FallingState(): CharacterState(STATE_FALLING){

}

FallingState::~FallingState(){

}

void FallingState::idle(Character* _char){
    _char->setState(STATE_IDLE);
}