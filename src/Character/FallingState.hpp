#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class FallingState : public CharacterState {
    public:
        FallingState();
        virtual ~FallingState();

        virtual bool idle(Character* _char);
};