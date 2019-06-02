#include "Menu.hpp"
Menu::Menu(float width, float height)
{

    if(!font.loadFromFile("arial.ttf"))
    {
        cerr<<"Erro ao ler fonte"<<endl;
    }
    menu_text[0].setFont(font);
    menu_text[0].setColor(sf::Color::Red);
    menu_text[0].setString("Jogar");
    menu_text[0].setPosition(sf::Vector2f(600/2 -50,((NUM_ITEMS+1)/4) * 100));

    menu_text[1].setFont(font);
    menu_text[1].setColor(sf::Color::White);
    menu_text[1].setString("Opcoes");
    menu_text[1].setPosition(sf::Vector2f(600/2 -50,((NUM_ITEMS+1)/4) * 200));

    menu_text[2].setFont(font);
    menu_text[2].setColor(sf::Color::White);
    menu_text[2].setString("Sair");
    menu_text[2].setPosition(sf::Vector2f(600/2 -50,((NUM_ITEMS+1)/4) * 300));

    selectedItem = 0;
    enabled = true;
}

Menu::~Menu()
{
    //dtor
}

void Menu::draw(){

    for(int i=0; i<NUM_ITEMS; i++)
    {
        engine->draw(menu_text[i]);
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

void Menu::update(){
    sf::Event event;
    while (engine->getWindow()->pollEvent(event)){
        switch(event.type)
        {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                    case sf::Keyboard::Up:
                        moveUp();
                    break;
                    case sf::Keyboard::Down:
                        moveDown();
                    break;
                    case sf::Keyboard::Return:
                        switch(getEnter())
                        {
                            case 0:
                                {
                                    cout<<"Jogar pressionado"<<endl;
                                    enabled=false;
                                }
                            break;
                            case 1:
                                cout<<"Opcao pressionado"<<endl;
                            break;
                            case 2:
                                engine->getWindow()->close();
                            break;
                            default: break;

                        }
                }
                break;
            case sf::Event::Closed:
                engine->getWindow()->close();
            default: break;
            break;
        }
    }
    draw();
}