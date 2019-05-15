#include "Menu.hpp"
Menu::Menu(float width, float height)
{

    if(!font.loadFromFile("arial.ttf"))
    {
        cerr<<"Erro ao ler fonte"<<endl;
    }
    menu_text[0].setFont(font);
    menu_text[0].setColor(sf::Color::White);
    menu_text[0].setString("Jogar");
    menu_text[0].setPosition(sf::Vector2f(width/2,(NUM_ITEMS+1)/4 * 1));

    menu_text[1].setFont(font);
    menu_text[1].setColor(sf::Color::White);
    menu_text[1].setString("Opcoes");
    menu_text[1].setPosition(sf::Vector2f(width/2,(NUM_ITEMS+1)/4 * 2));

    menu_text[2].setFont(font);
    menu_text[2].setColor(sf::Color::White);
    menu_text[2].setString("Sair");
    menu_text[2].setPosition(sf::Vector2f(width/2,(NUM_ITEMS+1)/4 * 3));

    selectedItem = 0;
}

Menu::~Menu()
{
    //dtor
}

void Menu::draw(sf::RenderWindow &window){

    for(int i=0; i<NUM_ITEMS; i++)
    {
        window.draw(menu_text[i]);
    }
}
void Menu::moveUp(){

    if(selectedItem -1 >= 0)
    {
        menu_text[selectedItem].setColor(sf::Color::White);
        selectedItem--;
        menu_text[selectedItem].setColor(sf::Color::Red);
     }
}
void Menu::moveDown(){

    if(selectedItem +1 < NUM_ITEMS)
    {
        menu_text[selectedItem].setColor(sf::Color::White);
        selectedItem++;
        menu_text[selectedItem].setColor(sf::Color::Red);
     }
}
