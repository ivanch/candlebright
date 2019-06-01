#pragma once
#include "includes.hpp"
#include "Entity.hpp"
#include "LinkedList.hpp"

class EntityList
{
    public:
        EntityList();
        ~EntityList();

        LinkedList<Entity> entity_list;

    protected:

    private:
};
