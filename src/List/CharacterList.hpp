#pragma once

#include <set>
#include "../Character/Character.hpp"

class CharacterList {
    public:
        std::set<Character*> characters;

        void add(Character* _el){
            characters.insert(_el);
        }
        void remove(Character* _el){
            characters.erase(_el);
        }
        void clear(){
            std::set<Character*>::iterator itr;
            for(itr = begin(); itr != end(); ++itr){
                delete *itr;
            }
            characters.clear();
        }
        std::set<Character *>::iterator begin(){ return characters.begin(); }
        std::set<Character *>::iterator end(){ return characters.end(); }

};