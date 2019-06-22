#include "City.hpp"

Phases::City::City(){
    Obstacles::Platform* p;
    p = new Obstacles::Platform(sf::Vector2f(1510.f, 80.f), sf::Vector2f(0.f, 733.f), new sf::Sprite (*getTexture("sprites/ground.png"))); // Chão
    addObstacle(p);
    p = new Obstacles::Platform(sf::Vector2f(1150.f, 10.f), sf::Vector2f(300.f, 620.f)); // Platforma branca
    addObstacle(p);


    Obstacles::Obstacle* o;
    o = new Obstacles::Wall(sf::Vector2f(50.f, 10.f), sf::Vector2f(220.f, 670.f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Fire(sf::Vector2f(130.f, 675.f), 25);
    addObstacle(o);
    o = new Obstacles::Black_Hole(sf::Vector2f(500.f, 650.f), 40);
    addObstacle(o);

    /* Bordas do mapa */
    o = new Obstacles::Wall(sf::Vector2f(10.f, 800.f), sf::Vector2f(0.f, 0.f), sf::Color::Black);
    addObstacle(o);
    o = new Obstacles::Wall(sf::Vector2f(10.f, 800.f), sf::Vector2f(1500.f, 0.f), sf::Color::Black);
    addObstacle(o);

    Enemy* e;
    e = new Zombie(sf::Vector2f(182.f, 600.f));
    addCharacter(e);
    e = new Hell_Demon(sf::Vector2f(500.f, 540.f));
    addCharacter(e);
    e = new Hell_Demon(sf::Vector2f(550.f, 540.f));
    addCharacter(e);
    e = new Dressed_Zombie(sf::Vector2f(800.f, 540.f));
    addCharacter(e);
    e = new Dressed_Zombie(sf::Vector2f(830.f, 540.f));
    addCharacter(e);
    e = new Hell_Demon(sf::Vector2f(1200.f, 540.f));
    addCharacter(e);
    e = new Dressed_Zombie(sf::Vector2f(1300.f, 540.f));
    addCharacter(e);

    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background1.png")){
        std::cerr << "Erro ao ler background..." << std::endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition(sf::Vector2f(0.f, 300.f));

    Music* background_music = new Music("songs/city_theme.ogg");
    background_music->run();
}
Phases::City::~City(){}

const sf::Vector2f Phases::City::getSpawnPoint() const {
    return sf::Vector2f(50.f, 600.f);
}