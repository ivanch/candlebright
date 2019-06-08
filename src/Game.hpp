#include "includes.hpp"
#include "Entity.hpp"
#include "World1.hpp"
#include "World2.hpp"
#include "Player.hpp"
#include "Engine.hpp"
#include "Menu.hpp"

class Game {
    private:
        sf::RenderWindow* window;
        Engine engine;

        Player player1;
        Player player2;
        World* world;

        Menu menu;
        bool menuEnabled;

    public:
        Game();
        ~Game();

        void run();
        void update();

        void draw(sf::RenderWindow& window);
};
