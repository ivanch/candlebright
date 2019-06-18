#pragma once
#include "includes.hpp"
#include "World.hpp"
#include "Platform.hpp"
#include "Enemies/Zombie.hpp"
#include "Enemies/Ghost.hpp"
#include "Enemies/HellDemon.hpp"
#include "Enemies/ClothedZombie.hpp"
#include "Obstacles/Wall.hpp"
#include "Obstacles/Fire.hpp"
#include "Obstacles/BlackHole.hpp"

class World_1 : public World {
    public:
        World_1();
        ~World_1();
};