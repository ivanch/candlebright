#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class JumpingState : public CharacterState {
    public:
        JumpingState();
        virtual ~JumpingState();

        virtual void falling(Character* _char);
};