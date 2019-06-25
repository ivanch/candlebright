#include "CharacterState.hpp"

CharacterStates::CharacterState::CharacterState(State _state): state(_state){

}

CharacterStates::CharacterState::~CharacterState(){}

const bool CharacterStates::CharacterState::idle(Characters::Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para idle" << std::endl;
    return false;
}

const bool CharacterStates::CharacterState::walking(Characters::Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para walking" << std::endl;
    return false;
}

const bool CharacterStates::CharacterState::jumping(Characters::Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para jumping" << std::endl;
    return false;
}

const bool CharacterStates::CharacterState::falling(Characters::Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para falling" << std::endl;
    return false;
}

const bool CharacterStates::CharacterState::attacking(Characters::Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para attacking" << std::endl;
    return false;
}