#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class IdleState : public CharacterState {
    public:
        IdleState();
        virtual ~IdleState();

        virtual const bool idle(Character* _char);
        virtual const bool jumping(Character* _char);
        virtual const bool walking(Character* _char);
        virtual const bool falling(Character* _char);
        virtual const bool attacking(Character* _char);
};