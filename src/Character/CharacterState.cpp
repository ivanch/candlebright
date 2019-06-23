#include "CharacterState.hpp"

CharacterState::CharacterState(State _state): state(_state){

}

CharacterState::~CharacterState(){}

const bool CharacterState::idle(Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para idle" << std::endl;
    return false;
}

const bool CharacterState::walking(Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para walking" << std::endl;
    return false;
}

const bool CharacterState::jumping(Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para jumping" << std::endl;
    return false;
}

const bool CharacterState::falling(Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para falling" << std::endl;
    return false;
}

const bool CharacterState::attacking(Character* _char){
    //std::cerr << "Mudança de CharacterState ilegal de " << getState() << " para attacking" << std::endl;
    return false;
}