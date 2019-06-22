#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class WalkingState : public CharacterState {
    public:
        WalkingState();
        virtual ~WalkingState();

        virtual const bool idle(Character* _char);
        virtual const bool jumping(Character* _char);
        virtual const bool falling(Character* _char);
        virtual const bool attacking(Character* _char);
};