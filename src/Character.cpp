#include "Character.hpp"

vector<Character*> Character::characters;

Character::Character(){
    characters.push_back(this);
}

Character::~Character(){
    for(auto itr = characters.begin(); itr != characters.end(); ++itr){
        if(*itr == this){
            characters.erase(itr);
        }
    }
}
