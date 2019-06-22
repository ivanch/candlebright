#include "Cemitery.hpp"

Phases::Cemitery::Cemitery(){
    sf::Sprite* ground2 = new sf::Sprite(*getTexture("sprites/ground2.png"));

    Obstacles::Platform* p;
    p = new Obstacles::Platform(sf::Vector2f(1510.f, 80.f), sf::Vector2f(0.f, 733.f), ground2); // Chão
    addObstacle(p);

    Obstacles::Obstacle* o;
    o = new Obstacles::Platform(sf::Vector2f(25.f, 10.f), sf::Vector2f(215.f, 670.f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Platform(sf::Vector2f(25.f, 10.f), sf::Vector2f(215.f, 700.f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Platform(sf::Vector2f(25.f, 10.f), sf::Vector2f(230.f, 600.f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Platform(sf::Vector2f(25.f, 10.f), sf::Vector2f(230.f, 635.f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Platform(sf::Vector2f(15.f, 10.f), sf::Vector2f(250.f, 550.f), sf::Color::Cyan);
    addObstacle(o);

    o = new Obstacles::Black_Hole(sf::Vector2f(500.f, 650.f), 40);
    addObstacle(o);
    o = new Obstacles::Fire(sf::Vector2f(450.f, 650.f), 40);
    addObstacle(o);

    /* Bordas do mapa */
    o = new Obstacles::Wall(sf::Vector2f(10.f, 800.f), sf::Vector2f(0.f, 0.f), sf::Color::Black);
    addObstacle(o);
    o = new Obstacles::Wall(sf::Vector2f(10.f, 800.f), sf::Vector2f(1500.f, 0.f), sf::Color::Black);
    addObstacle(o);

    Enemy* e;
    e = new Zombie(sf::Vector2f(180.f, 600.f));
    addCharacter(e);
    e = new Hell_Demon(sf::Vector2f(550.f, 540.f));
    addCharacter(e);
    e = new Ghost(sf::Vector2f(350.f, 500.f));
    addCharacter(e);
    e = new Dressed_Zombie(sf::Vector2f(800.f, 540.f));
    addCharacter(e);
    e = new Dressed_Zombie(sf::Vector2f(830.f, 540.f));
    addCharacter(e);
    e = new Hell_Demon(sf::Vector2f(1200.f, 540.f));
    addCharacter(e);
    e = new Dressed_Zombie(sf::Vector2f(1300.f, 540.f));
    addCharacter(e);
    e = new Sylathus(sf::Vector2f(1500.f, 550.f));
    addCharacter(e);


    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background2.png")){
        std::cerr << "Erro ao ler background..." << std::endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition(sf::Vector2f(0.f, 230.f));

    background_music = new Music("songs/cemitery_theme.ogg");
    background_music->run();
}
Phases::Cemitery::~Cemitery(){
    background_music->stop();
    delete background_music;
}

const sf::Vector2f Phases::Cemitery::getSpawnPoint() const {
    return sf::Vector2f(50.f, 600.f);
}