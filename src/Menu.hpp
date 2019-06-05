#pragma once
#include "includes.hpp"
#include "Entity.hpp"

#define MAIN_MENU       0
#define WORLD_MENU      1
#define PLAYER_MENU     2
#define SETTINGS_MENU   3

#define MAX_MENU        4
#define MAX_ITEMS       10

class Menu : public Entity
{
    public:
        Menu(float width, float height);
        ~Menu();

        virtual void draw();
        void moveUp();
        void moveDown();
        int getEnter(){ return selectedItem; }
        virtual void update();
        bool isEnabled(){ return enabled; }

        const int getSelectedWorld() const { return world; }
        const int getSelectedPlayers() const { return players; }

    protected:

    private:
        sf::Text menu_text[MAX_MENU][MAX_ITEMS];
        sf::Font font;
        sf::Clock enterClock;
        int selectedItem;
        bool enabled;
        int currentMenu;

        int world;
        int players;

        int getMenuItems(int _menu);
        void addMenuItem(int _menu, string _title, bool isPrimary, sf::Font _font);

};
