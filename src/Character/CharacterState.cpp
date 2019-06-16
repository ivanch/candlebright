#include "CharacterState.hpp"

CharacterState::CharacterState(State _state): state(_state){

}

CharacterState::~CharacterState(){}

void CharacterState::idle(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para idle" << endl;
}

void CharacterState::walking(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para walking" << endl;
}

void CharacterState::jumping(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para jumping" << endl;
}

void CharacterState::falling(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para falling" << endl;
}

void CharacterState::attacking(Character* _char){
    cerr << "Mudança de CharacterState ilegal de " << getState() << " para attacking" << endl;
}