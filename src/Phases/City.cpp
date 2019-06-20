#include "City.hpp"

City::City(){
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

    Obstacle* o;
    o = new Wall({10,50},{100,700}, sf::Color::Cyan);
    addObstacle(o);
    o = new Wall({20,50},{50,500}, sf::Color::Cyan);
    addObstacle(o);
    o = new Wall({20,50},{125,450}, sf::Color::Cyan);
    addObstacle(o);
    o = new Fire({130,675}, 25);
    addObstacle(o);
    o = new Black_Hole({500,650}, 40);
    addObstacle(o);

    Enemy* e;
    e = new Zombie({150,650});
    addCharacter(e);
    e = new Dressed_Zombie({250,550});
    addCharacter(e);
    e = new Ghost({50,550});
    addCharacter(e);
    e = new Ghost({300,550});
    addCharacter(e);
    e = new Hell_Demon({200,350});
    addCharacter(e);
    e = new Hell_Demon({400,600});


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
City::~City(){}
