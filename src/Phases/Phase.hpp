#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <math.h>

#include "../System/Engine.hpp"
#include "../System/Entity.hpp"
#include "../Thing.hpp"
#include "../System/Music.hpp"
#include "CollisionManager.hpp"
#include "../List/LinkedList.hpp"
#include "../List/EntityList.hpp"
#include "../List/CharacterList.hpp"
#include "../List/ThingsList.hpp"
#include "../List/ObstacleList.hpp"
#include "../Character/Player.hpp"
#include "../Enemies/Zombie.hpp"
#include "../Enemies/Ghost.hpp"
#include "../Enemies/HellDemon.hpp"
#include "../Enemies/DressedZombie.hpp"
#include "../Enemies/Sylathus.hpp"

class Phase : public Entity {
    protected:
        sf::Sprite* background;
        EntityList entities;
        ThingsList things;
        CharacterList characters;
        ObstaclesList obstacles;
        CollisionManager col_mngr;

        float getDistance(sf::Vector2f p1, sf::Vector2f p2);

    public:
        Phase();
        ~Phase();
        void setBackground(sf::Sprite* _bg) { background = _bg; }
        sf::Sprite* getBackground() { return background; }
        void update(); // Atualizar a lista de entidades dentro do mundo
        void draw(Engine& engine);
        void drawAll(Engine& engine);
        void gravity();

        void loadEnemies(int act_world);

        void addEntity(Entity* _e) { entities.add(_e); }
        void addThing(Thing* _thing) { things.add(_thing); addEntity(static_cast<Entity*>(_thing)); }
        void addCharacter(Character* _char){ characters.add(_char); addThing(static_cast<Thing*>(_char)); }
        void addObstacle(Obstacle* _obs){ obstacles.add(_obs); addThing(static_cast<Thing*>(_obs)); }

        CharacterList* getCharList(){ return &characters;}

        sf::Vector2f getRandomPosition(const sf::View& view);
};
