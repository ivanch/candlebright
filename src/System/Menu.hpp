#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <time.h>

#define MAX_MENU        4
#define MAX_ITEMS       10

class Menu : public Entity
{
    public:
        Menu(float width, float height);
        ~Menu();

        virtual void draw(Engine& engine);
        void moveUp();
        void moveDown();
        virtual void update(){}
        void update(Engine* engine);
        bool isEnabled(){ return enabled; }

        const int getSelectedPhase() const { return world; }
        const int getSelectedPlayers() const { return players; }

    private:
        sf::Text menu_text[MAX_MENU][MAX_ITEMS];
        sf::Font font;
        sf::Clock enterClock;
        sf::Sprite* spriteMenu;
        int selectedItem;
        bool enabled;
        int currentMenu;

        int world;
        int players;

        int getMenuItems(int _menu);
        void addMenuItem(int _menu, std::string _title, bool isPrimary, sf::Font _font);

        enum {
            MENU_MAIN,
            MENU_PHASES,
            MENU_PLAYERS,
            MENU_PLAYER_NAME_1,
            MENU_PLAYER_NAME_2
        };

};
