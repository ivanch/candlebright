#include "Cemitery.hpp"

Phases::Cemitery::Cemitery(){
    sf::Sprite* ground2 = new sf::Sprite(*getTexture("sprites/ground2.png"));

    Obstacles::Platform* p;
    p = new Obstacles::Platform(sf::Vector2f(1440.f, 100.f), sf::Vector2f(0.f, 720.f), ground2); // Chão
    addObstacle(p);
    p = new Obstacles::Platform(sf::Vector2f(100.f, 10.f), sf::Vector2f(150.f, 625.f), sf::Color::Black); // Platforma Preta
    p->setMove(sf::Vector2f(1000.f, 0.f));
    p->setMoveSpeed(sf::Vector2f(1.f, 0.f));
    addObstacle(p);

    Obstacles::Obstacle* o;
    o = new Obstacles::Wall(sf::Vector2f(10.f, 40.f), sf::Vector2f(100.f, 720.f), sf::Color::Cyan);
    addObstacle(o);
    

    Enemy* e;
    e = new Zombie(sf::Vector2f(150.f, 600.f));
    addCharacter(e);
    e = new Zombie(sf::Vector2f(200.f, 600.f));
    addCharacter(e);
    e = new Zombie(sf::Vector2f(250.f, 600.f));
    addCharacter(e);
    e = new Zombie(sf::Vector2f(300.f, 600.f));
    addCharacter(e);
    e = new Sylathus(sf::Vector2f(500.f, 550.f));
    addCharacter(e);


    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background2.png")){
        std::cerr << "Erro ao ler background..." << std::endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition(sf::Vector2f(0.f, 230.f));

    Music* background_music = new Music("songs/cemitery_theme.ogg");
    background_music->run();
}
Phases::Cemitery::~Cemitery(){}

const sf::Vector2f Phases::Cemitery::getSpawnPoint() const {
    return sf::Vector2f(50.f, 600.f);
}