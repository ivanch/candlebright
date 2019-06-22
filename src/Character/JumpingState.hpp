#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class JumpingState : public CharacterState {
    public:
        JumpingState();
        virtual ~JumpingState();

        virtual const bool walking(Character* _char);
        virtual const bool falling(Character* _char);
};