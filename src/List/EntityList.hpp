#pragma once
#include "../includes.hpp"
#include "../System/Entity.hpp"
#include "LinkedList.hpp"

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

        list<Entity*> entities;

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
