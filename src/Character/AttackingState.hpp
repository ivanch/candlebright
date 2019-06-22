#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class AttackingState : public CharacterState {
    public:
        AttackingState();
        virtual ~AttackingState();

        virtual const bool idle(Character* _char);
        virtual const bool falling(Character* _char);
};