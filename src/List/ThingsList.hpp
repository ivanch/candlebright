#pragma once
#include "../Thing.hpp"
#include <list>

class ThingsList {
    public:
        std::list<Thing*> things;

        virtual void add(Thing* _el){
            things.push_back(_el);
        }
        virtual void remove(Thing* _el){
            things.remove(_el);
        }

        std::list<Thing*>::iterator begin(){ return things.begin(); }
        std::list<Thing*>::iterator end(){ return things.end(); }
};