#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class WalkingState : public CharacterState {
    public:
        WalkingState();
        virtual ~WalkingState();

        virtual bool idle(Character* _char);
        virtual bool jumping(Character* _char);
        virtual bool falling(Character* _char);
        virtual bool attacking(Character* _char);
};