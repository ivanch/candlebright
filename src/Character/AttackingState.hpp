#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class AttackingState : public CharacterState {
    public:
        AttackingState();
        virtual ~AttackingState();

        virtual void idle(Character* _char);
        virtual void walking(Character* _char);
        virtual void jumping(Character* _char);
        virtual void falling(Character* _char);
};