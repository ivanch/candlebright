#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class FallingState : public CharacterState {
    public:
        FallingState();
        virtual ~FallingState();

        virtual const bool walking(Character* _char);
        virtual const bool idle(Character* _char);
};