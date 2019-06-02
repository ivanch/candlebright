#pragma once
#include "includes.hpp"
#include "Entity.hpp"

#define NUM_ITEMS 3
class Menu : public Entity
{
    public:
        Menu(float width, float height);
        ~Menu();

        virtual void draw();
        void moveUp();
        void moveDown();
        int getEnter(){return selectedItem;}
        virtual void update();
        bool isEnabled(){ return enabled; }

    protected:

    private:
        sf::Text menu_text[NUM_ITEMS];
        sf::Font font;
        int selectedItem;
        bool enabled;

};
