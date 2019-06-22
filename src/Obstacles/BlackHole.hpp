#pragma once

#include <SFML/Graphics.hpp>
#include "../Animatable.hpp"
#include "Obstacle.hpp"

namespace Obstacles {

    class Black_Hole : public Obstacle, public Animatable {    
        public:
            Black_Hole(sf::Vector2f pos, float _size);
            ~Black_Hole();

            virtual void update();
            virtual void draw(Engine& engine);
            virtual const sf::Vector2f getPos() const;
    };

};