#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class JumpingState : public CharacterState {
    public:
        JumpingState();
        virtual ~JumpingState();

        virtual bool falling(Character* _char);
};