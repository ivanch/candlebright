#include "Entity.hpp"

vector<Entity*> Entity::entities;

Entity::Entity(){
    entities.push_back(this);
}

Entity::~Entity(){
    for(int i = 0; i < entities.size(); i++)
        if(entities[i] == this) entities.erase(entities.begin()+i);
}
