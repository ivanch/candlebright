#pragma once
#include "includes.hpp"

class Listener{
    public:
        static vector<Listener*> listeners;

        Listener();
        ~Listener();
        virtual void onUpdate() = 0;
};
