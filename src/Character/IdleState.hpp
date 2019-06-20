#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class IdleState : public CharacterState {
    public:
        IdleState();
        virtual ~IdleState();

        virtual bool idle(Character* _char);
        virtual bool jumping(Character* _char);
        virtual bool walking(Character* _char);
        virtual bool falling(Character* _char);
        virtual bool attacking(Character* _char);
};