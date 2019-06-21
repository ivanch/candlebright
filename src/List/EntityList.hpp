#pragma once

#include <SFML/Graphics.hpp>
#include "../System/Entity.hpp"
#include "LinkedList.hpp"

#include <list>

class EntityList 
{
    public:
        EntityList(){ }
        ~EntityList(){ }

        /*LinkedList<Entity> entity_list;

        virtual void add(Entity* _el){
            entity_list.insertBack(_el);
        }
        virtual void remove(Entity* _el){
            entity_list.removeNth(_el);
        }*/

        std::list<Entity*> entities;

        virtual void add(Entity* _el){
            entities.push_back(_el);
        }
        virtual void remove(Entity* _el){
            entities.remove(_el);
        }

        std::list<Entity*>::iterator begin(){ return entities.begin(); }
        std::list<Entity*>::iterator end(){ return entities.end(); }

    protected:

    private:
};
