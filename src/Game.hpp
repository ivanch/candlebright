#include "includes.hpp"
#include "Object.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "Engine.hpp"
#include "Enemy.hpp"

class Game{
    private:
        sf::RenderWindow window;
        sf::View view;

        sf::Texture backgroundTexture;
        sf::Sprite background;

        World w1;

    public:
        Game();
        ~Game();

        void run();
};
