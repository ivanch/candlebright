#include "Listener.hpp"

vector<Listener*> Listener::listeners;

Listener::Listener(){
    listeners.push_back(this);
}

Listener::~Listener(){
    for(int i = 0; i < listeners.size(); i++){
        if(listeners[i] == this){
            listeners.erase(listeners.begin()+i);
            break;
        }
    }
}