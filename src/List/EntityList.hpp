#pragma once
#include "../includes.hpp"
#include "../Entity.hpp"
#include "LinkedList.hpp"
#include "List.hpp"

class EntityList : public List<Entity*>
{
    public:
        EntityList(){ }
        ~EntityList(){ }

        LinkedList<Entity> entity_list;

        virtual void add(Entity* _el){
            entity_list.insertBack(_el);
        }
        virtual void remove(Entity* _el){
            entity_list.removeNth(_el);
        }

    protected:

    private:
};
