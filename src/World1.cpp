#include "World1.hpp"

World_1::World_1(){
    Platform* p;
    p = new Platform({1510,80},{0,733}, new sf::Sprite (*getTexture("sprites/ground.png"))); // Chão
    addThing(p);
    p = new Platform({1280,10},{150,625}); // Platforma branca
    addThing(p);
    p = new Platform({1280,5},{200,525}, sf::Color::Red); // Platforma vermelha
    p->setMoving(true);
    p->setMove({100,0});
    p->setMoveSpeed({0.5,0});
    addThing(p);

    p = new Platform({50,2},{-50,700}, sf::Color::Magenta); // Platforma rosa
    p->setMoving(true);
    p->setMove({0,100});
    p->setMoveSpeed({0,0.5});
    addThing(p);

    Obstacle* o;
    o = new Obstacle1({10,50},{100,650}, sf::Color::Cyan);
    addThing(o);
    o = new Obstacle1({20,50},{50,500}, sf::Color::Cyan);
    addThing(o);
    o = new Obstacle1({20,50},{125,450}, sf::Color::Cyan);
    addThing(o);

    Enemy* e;
    e = new Zombie({150,650});
    addCharacter(e);
    e = new Zombie({250,550});
    addCharacter(e);


    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background1.png")){
        cerr << "Erro ao ler background..." << endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition({0,300});

    Music* background_music = new Music("songs/city_theme.ogg");
    background_music->run();
}
World_1::~World_1(){}
