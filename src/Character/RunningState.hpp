#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

namespace CharacterStates {
    class RunningState : public CharacterState {
        public:
            RunningState();
            virtual ~RunningState();

            virtual const bool idle(Characters::Character* _char);
            virtual const bool walk(Characters::Character* _char);
            virtual const bool falling(Characters::Character* _char);
    };
}