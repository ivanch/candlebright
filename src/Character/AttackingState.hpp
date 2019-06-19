#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class AttackingState : public CharacterState {
    public:
        AttackingState();
        virtual ~AttackingState();

        virtual bool idle(Character* _char);
        virtual bool falling(Character* _char);
};