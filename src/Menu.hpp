#pragma once
#include "SFML/Graphics.hpp"
#include "includes.hpp"

#define NUM_ITEMS 3
class Menu
{
    public:
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow* window);
        void moveUp();
        void moveDown();
        int getEnter(){return selectedItem;}

    protected:

    private:
        sf::Text menu_text[NUM_ITEMS];
        sf::Font font;
        int selectedItem;

};
