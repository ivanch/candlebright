#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class FallingState : public CharacterState {
    public:
        FallingState();
        virtual ~FallingState();

        virtual void idle(Character* _char);
};