#pragma once

#include <list>
#include "../Thing.hpp"

class ThingsList {
    public:
        std::list<Thing*> things;

        void add(Thing* _el){
            things.push_back(_el);
        }
        void remove(Thing* _el){
            things.remove(_el);
        }
        void clear(){
            std::list<Thing*>::iterator itr;
            for(itr = begin(); itr != end(); ++itr){
                delete *itr;
            }
            things.clear();
        }

        std::list<Thing*>::iterator begin(){ return things.begin(); }
        std::list<Thing*>::iterator end(){ return things.end(); }
};