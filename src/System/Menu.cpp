#include "Menu.hpp"
Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("fonts/OldLondon.ttf"))
    {
        std::cerr<<"Erro ao ler fonte"<<std::endl;
    }

    sf::Texture* textureMenu = new sf::Texture;
    spriteMenu = new sf::Sprite;
    int menu_opt;
    menu_opt=rand()%2;
    std::cout<<menu_opt;
    if(menu_opt==0){
        if (!textureMenu->loadFromFile("sprites/menubg1.png"))
            std::cerr << "Erro ao ler background..." << std::endl;
    }
    else if(menu_opt==1){
        if (!textureMenu->loadFromFile("sprites/menubg2.png"))
            std::cerr << "Erro ao ler background..." << std::endl;
    }

    spriteMenu->setTexture(*textureMenu);

    addMenuItem(MENU_MAIN, "Jogar", true, font);
    addMenuItem(MENU_MAIN, "Sair", false, font);

    addMenuItem(MENU_PHASES, "Cidade (1)", true, font);
    addMenuItem(MENU_PHASES, "Cemiterio (2)", false, font);

    addMenuItem(MENU_PLAYERS, "1 Jogador", true, font);
    addMenuItem(MENU_PLAYERS, "2 Jogadores", false, font);

    enabled = true;
    selectedItem = 0;
    currentMenu = MENU_MAIN;

}
Menu::~Menu()
{
    //dtor
}

void Menu::draw(Engine& engine){
    engine.draw(*spriteMenu);
    for(int i=0; i<getMenuItems(currentMenu); i++){
        engine.draw(menu_text[currentMenu][i]);
    }
}

void Menu::moveUp(){
    if(selectedItem -1 >= 0)
    {
        menu_text[currentMenu][selectedItem].setFillColor(sf::Color::White);
        selectedItem--;
        menu_text[currentMenu][selectedItem].setFillColor(sf::Color::Red);
     }
}

void Menu::moveDown(){

    if(selectedItem +1 < getMenuItems(currentMenu))
    {
        menu_text[currentMenu][selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu_text[currentMenu][selectedItem].setFillColor(sf::Color::Red);
     }
}

void Menu::update(Engine* engine){
    sf::Event event;
    while (engine->getWindow()->pollEvent(event)){
        if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::Up){
                moveUp();
            }else if(event.key.code == sf::Keyboard::Down){
                moveDown();
            }else if(event.key.code == sf::Keyboard::Enter){
                switch (currentMenu){
                    case MENU_MAIN:
                        if(selectedItem == 0) currentMenu = MENU_PHASES;
                        else if(selectedItem == 2) engine->getWindow()->close();
                        selectedItem = 0;
                        break;
                    case MENU_PHASES:
                        if(selectedItem == 0) world = 1;
                        else if(selectedItem == 1) world = 2;
                        currentMenu = MENU_PLAYERS;
                        selectedItem = 0;
                        break;
                    case MENU_PLAYERS:
                        if(selectedItem == 0) players = 1;
                        else if(selectedItem == 1) players = 2;
                        enabled = false;
                        break;
                    default:
                        break;
                }
            }
        }else if(event.type == sf::Event::Closed){
            engine->getWindow()->close();
        }
    }
}

int Menu::getMenuItems(int _menu){
    if(_menu == MENU_MAIN) return 3;
    else if(_menu == MENU_PHASES) return 2;
    else if(_menu == MENU_PLAYERS) return 2;

    return -1;
}

void Menu::addMenuItem(int _menu, std::string _title, bool isPrimary, sf::Font _font){
    int index = 0;
    for(int i = 0; i < MAX_ITEMS; i++){
        if(menu_text[_menu][i].getFont() == NULL){
            index = i;
            break;
        }
    }
    menu_text[_menu][index].setFont(font);
    menu_text[_menu][index].setFillColor(isPrimary ? sf::Color::Red : sf::Color::White);
    menu_text[_menu][index].setString(_title);
    menu_text[_menu][index].setPosition(sf::Vector2f(600/2 -35, 75 * (index+1)));
}
