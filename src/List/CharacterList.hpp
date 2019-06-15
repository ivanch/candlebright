#include "../Character.hpp"
#include "List.hpp"
#include <set>

class CharacterList : public List<Character*> {
    public:
        set<Character*> characters;

        virtual void add(Character* _el){
            characters.insert(_el);
        }
        virtual void remove(Character* _el){
            for(auto itr = characters.begin(); itr != characters.end(); ++itr){
                if(*itr == _el){
                    characters.erase(itr, itr);
                }
            }
        }
        set<Character *>::iterator begin(){ return characters.begin(); }
        set<Character *>::iterator end(){ return characters.end(); }

};