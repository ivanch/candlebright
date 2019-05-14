#include "Object.hpp"

vector<Object*> Object::objects;

Object::Object(){
    objects.push_back(this);
}

Object::~Object(){
    for(int i = 0; i < objects.size(); i++)
        if(objects[i] == this) objects.erase(objects.begin()+i);
}
