#include "CharacterState.hpp"

CharacterState::CharacterState(State _state): state(_state){

}

CharacterState::~CharacterState(){}

bool CharacterState::idle(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para idle" << endl;
    return false;
}

bool CharacterState::walking(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para walking" << endl;
    return false;
}

bool CharacterState::jumping(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para jumping" << endl;
    return false;
}

bool CharacterState::falling(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para falling" << endl;
    return false;
}

bool CharacterState::attacking(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para attacking" << endl;
    return false;
}