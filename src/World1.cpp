#include "World1.hpp"
#include "TextureManager.hpp"

World_1::World_1(){
    Plataform* p;
    p = new Plataform({1280,30},{0,720}, TextureManager::grass); // Chão
    addObject(p);
    p = new Plataform({1280,10},{150,625}); // Plataforma branca
    addObject(p);
    p = new Plataform({1280,5},{200,550}, sf::Color::Red); // Plataforma vermelha
    p->setMoving(true);
    p->setMove({100,0});
    p->setMoveSpeed({0.5,0});
    addObject(p);

    p = new Plataform({50,2},{-50,700}, sf::Color::Magenta); // Plataforma rosa
    p->setMoving(true);
    p->setMove({0,100});
    p->setMoveSpeed({0,0.5});
    addObject(p);

    Obstacle* o;
    o = new Obstacle1({10,50},{100,650}, sf::Color::Cyan);
    addObject(o);
    o = new Obstacle1({20,50},{50,500}, sf::Color::Cyan);
    addObject(o);
    o = new Obstacle1({20,50},{125,450}, sf::Color::Cyan);
    addObject(o);

    Enemy* e;
    e = new Enemy_1({150,650});
    addObject(e);
    e = new Enemy_1({250,550});
    addObject(e);


    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background1.png")){
        cerr << "Erro ao ler background..." << endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition({0,300});
}
World_1::~World_1(){}
