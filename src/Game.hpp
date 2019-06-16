#include "includes.hpp"
#include "Entity.hpp"
#include "World1.hpp"
#include "World2.hpp"
#include "Character/Player.hpp"
#include "Engine.hpp"
#include "Menu.hpp"

class Game {
    private:
        Engine engine;
        sf::RenderWindow* window;

        Player player1;
        Player player2;
        World* world;
        sf::View view;


        Menu menu;
        bool menuEnabled;

    public:
        Game();
        ~Game();

        void run();
        void update();

        sf::View* getView() { return &view; }
        void setView(sf::View _view){ this->view=_view; }

        void draw(sf::RenderWindow& window);
};
