#pragma once

#include <set>
#include "../Character/Character.hpp"

class CharacterList {
    public:
        std::set<Character*> characters;

        virtual void add(Character* _el){
            characters.insert(_el);
        }
        virtual void remove(Character* _el){
            characters.erase(_el);
        }
        std::set<Character *>::iterator begin(){ return characters.begin(); }
        std::set<Character *>::iterator end(){ return characters.end(); }

};