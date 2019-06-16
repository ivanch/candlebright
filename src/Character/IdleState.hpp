#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class IdleState : public CharacterState {
    public:
        IdleState();
        virtual ~IdleState();

        virtual void jumping(Character* _char);
        virtual void walking(Character* _char);
        virtual void falling(Character* _char);
        virtual void attacking(Character* _char);
};