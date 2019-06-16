#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

class WalkingState : public CharacterState {
    public:
        WalkingState();
        virtual ~WalkingState();

        virtual void jumping(Character* _char);
        virtual void falling(Character* _char);
        virtual void attacking(Character* _char);
};