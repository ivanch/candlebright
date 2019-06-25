#pragma once

#include <SFML/Graphics.hpp>
#include "../System/Entity.hpp"
#include "LinkedList.hpp"

#include <list>

namespace Lists {
    class EntityList 
    {
        public:
            EntityList(){ }
            ~EntityList(){ }

            LinkedList<System::Entity> entity_list;

            void add(System::Entity* _el){
                entity_list.insertBack(_el);
            }
            void remove(System::Entity* _el){
                entity_list.removeNth(_el);
            }
            void clear(){
                for(int i = 0; i < size(); i++){
                    delete entity_list[i]->getData();
                }
                entity_list.clear();
            }
            int size(){
                return entity_list.getSize();
            }

            System::Entity* operator[](int chave){
                return entity_list[chave]->getData();
            }

            void operator[](std::string op){
                if(op != "update"){
                    std::cerr << "EntityList só suporta a operação 'update'." << std::endl;
                    return;
                }
                for(int i = 0; i < size(); i++){
                    entity_list[i]->getData()->update();
                }
            }
    };
}