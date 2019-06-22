#pragma once

#include <time.h>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Entity.hpp"

#define MAX_MENU        4
#define MAX_ITEMS       10

class Menu : public Entity
{
    public:
        Menu(float width, float height);
        ~Menu();

        virtual void draw(Engine& engine);
        virtual void update(){}
        void update(Engine* engine);
        void moveUp();
        void moveDown();

        const bool isEnabled() const { return enabled; }
        const int getSelectedPhase() const { return world; }
        const int getSelectedPlayers() const { return players; }

    private:
        sf::Text menu_text[MAX_MENU][MAX_ITEMS];
        sf::Text menuTitle;
        sf::Font font;
        sf::Clock enterClock;
        sf::Sprite* spriteMenu;
        sf::Sprite* spriteWhip;
        int selectedItem;
        bool enabled;
        int currentMenu;

        int world;
        int players;

        int getMenuItems(int _menu);
        void addMenuItem(int _menu, std::wstring _title, bool isPrimary, sf::Font _font);

        enum {
            MENU_MAIN,
            MENU_PHASES,
            MENU_PLAYERS
        };

};
