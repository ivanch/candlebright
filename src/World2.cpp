#include "World2.hpp"
#include "TextureManager.hpp"

World_2::World_2(){
    Plataform* p;
    p = new Plataform({1280,30},{0,720}, sf::Color(122,122,122)); // Chão
    addObject(p);
    p = new Plataform({100,10},{150,625}, sf::Color::Black); // Plataforma Preta
    p->setMove({1000,0});
    p->setMoveSpeed({1,0});
    addObject(p);

    Obstacle* o;
    o = new Obstacle1({10,50},{100,650}, sf::Color::Cyan);
    addObject(o);

    Enemy* e;
    e = new Enemy_1({150,650});
    addObject(e);
    e = new Enemy_1({200,650});
    addObject(e);
    e = new Enemy_1({250,650});
    addObject(e);
    e = new Enemy_1({300,650});
    addObject(e);


    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background2ALL.png")){
        cerr << "Erro ao ler background..." << endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition({0,300});

    Music* background_music = new Music("songs/cemitery_theme.ogg");
    background_music->run();
}
World_2::~World_2(){}
