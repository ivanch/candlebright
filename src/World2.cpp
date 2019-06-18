#include "World2.hpp"

World_2::World_2(){
    sf::Sprite* ground2 = new sf::Sprite(*getTexture("sprites/ground2.png"));
    Platform* p;
    p = new Platform({1440,100},{0,720}, ground2); // Chão
    addThing(p);
    p = new Platform({100,10},{150,625}, sf::Color::Black); // Platforma Preta
    p->setMove({1000,0});
    p->setMoveSpeed({1,0});
    addThing(p);

    Obstacle* o;
    o = new Wall({10,50},{100,650}, sf::Color::Cyan);
    addObstacle(o);
    o = new Fire({120,650});
    addObstacle(o);

    Enemy* e;
    e = new Zombie({150,650});
    addCharacter(e);
    e = new Zombie({200,650});
    addCharacter(e);
    e = new Zombie({250,650});
    addCharacter(e);
    e = new Zombie({300,650});
    addCharacter(e);
    e = new Sylathus({500,550});
    addThing(e);
    addCharacter(e);


    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background2.png")){
        cerr << "Erro ao ler background..." << endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition({0,230});

    Music* background_music = new Music("songs/cemitery_theme.ogg");
    background_music->run();
}
World_2::~World_2(){}
