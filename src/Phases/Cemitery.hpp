#pragma once

#include <SFML/Graphics.hpp>
#include "../Enemies/Zombie.hpp"
#include "../Enemies/Sylathus.hpp"
#include "../Obstacles/Platform.hpp"
#include "../Obstacles/Wall.hpp"
#include "../Obstacles/Fire.hpp"
#include "Phase.hpp"

class Cemitery : public Phase {
    public:
        Cemitery();
        ~Cemitery();

        virtual sf::Vector2f getSpawnPoint();
};
