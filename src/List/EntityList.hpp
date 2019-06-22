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

        LinkedList<Entity> entity_list;

        void add(Entity* _el){
            entity_list.insertBack(_el);
        }
        void remove(Entity* _el){
            entity_list.removeNth(_el);
        }
        void clear(){
            for(int i = 0; i < size(); i++){
                delete entity_list[i];
            }
            entity_list.clear();
        }
        int size(){
            return entity_list.getSize();
        }

        Entity* operator[](int chave){
            return entity_list[chave]->getData();
        }

    protected:

    private:
};
