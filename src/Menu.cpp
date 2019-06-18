#include "Menu.hpp"
Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("fonts/OldLondon.ttf"))
    {
        cerr<<"Erro ao ler fonte"<<endl;
    }

    sf::Texture* textureMenu = new sf::Texture;
    spriteMenu = new sf::Sprite;
    int menu_opt;
    srand(time(NULL));
    menu_opt=rand()%2;
    cout<<menu_opt;
    if(menu_opt==0){
        if (!textureMenu->loadFromFile("sprites/menubg1.png"))
            cerr << "Erro ao ler background..." << endl;
    }
    else if(menu_opt==1){
        if (!textureMenu->loadFromFile("sprites/menubg2.png"))
            cerr << "Erro ao ler background..." << endl;
    }

    spriteMenu->setTexture(*textureMenu);

    addMenuItem(MAIN_MENU, "Jogar", true, font);
    addMenuItem(MAIN_MENU, "Opcoes", false, font);
    addMenuItem(MAIN_MENU, "Sair", false, font);

    addMenuItem(WORLD_MENU, "Mundo 1", true, font);
    addMenuItem(WORLD_MENU, "Mundo 2", false, font);

    addMenuItem(PLAYER_MENU, "1 Jogador", true, font);
    addMenuItem(PLAYER_MENU, "2 Jogadores", false, font);

    enabled = true;
    selectedItem = 0;
    currentMenu = MAIN_MENU;

}
Menu::~Menu()
{
    //dtor
}

void Menu::draw(Engine* engine){
    engine->draw(*spriteMenu);
    for(int i=0; i<getMenuItems(currentMenu); i++){
        engine->draw(menu_text[currentMenu][i]);
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
                                    switch(currentMenu){
                                        case PLAYER_MENU: {
                                            enabled = false;
                                            players = 1;
                                        }
                                        break;
                                        case WORLD_MENU: {
                                            currentMenu = PLAYER_MENU;
                                            selectedItem = 0;
                                            world = 1;
                                        }
                                        break;
                                        case MAIN_MENU: {
                                            currentMenu = WORLD_MENU;
                                            selectedItem = 0;
                                        }
                                        break;
                                        default: break;
                                    }
                                }
                                break;
                            case 1:
                                    switch(currentMenu){
                                        case PLAYER_MENU: {
                                            enabled = false;
                                            players = 2;
                                        }
                                        break;
                                        case WORLD_MENU: {
                                            currentMenu = PLAYER_MENU;
                                            selectedItem = 0;
                                            world = 2;
                                        }
                                        break;
                                        case MAIN_MENU: {
                                            //currentMenu = SETTINGS_MENU;
                                            selectedItem = 0;
                                        }
                                        break;
                                        default: break;
                                    }
                                break;
                            case 2:
                                engine->getWindow()->close();
                                break;
                            default:
                              break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::Closed:
                engine->getWindow()->close();
                break;
            default:
                break;
        }
    }
}

int Menu::getMenuItems(int _menu){
    if(_menu == MAIN_MENU) return 3;
    else if(_menu == WORLD_MENU) return 2;
    else if(_menu == PLAYER_MENU) return 2;

    return -1;
}

void Menu::addMenuItem(int _menu, string _title, bool isPrimary, sf::Font _font){
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
