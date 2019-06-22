#pragma once

#include <SFML/Graphics.hpp>
#include "../Enemies/Zombie.hpp"
#include "../Enemies/Sylathus.hpp"
#include "../Obstacles/Platform.hpp"
#include "../Obstacles/Wall.hpp"
#include "../Obstacles/Fire.hpp"
#include "Phase.hpp"

namespace Phases {

    class Cemitery : public Phase {
        public:
            Cemitery();
            ~Cemitery();

            virtual const sf::Vector2f getSpawnPoint() const;
    };

}