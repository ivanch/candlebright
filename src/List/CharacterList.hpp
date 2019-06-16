#include "../Character/Character.hpp"
#include "List.hpp"
#include <set>

class CharacterList : public List<Character*> {
    public:
        set<Character*> characters;

        virtual void add(Character* _el){
            characters.insert(_el);
        }
        virtual void remove(Character* _el){
            characters.erase(_el);
        }
        set<Character *>::iterator begin(){ return characters.begin(); }
        set<Character *>::iterator end(){ return characters.end(); }

};