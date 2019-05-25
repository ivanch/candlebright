#include "Character.hpp"

vector<Character*> Character::characters;

Character::Character(){
    characters.push_back(this);
}

Character::~Character(){
    for(int i = 0; i < Character::characters.size(); i++){
        if(Character::characters[i] == this){
            Character::characters.erase(characters.begin()+i);
        }
    }
}
