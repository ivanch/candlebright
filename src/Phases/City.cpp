#include "City.hpp"

City::City(){
    Platform* p;
    p = new Platform({1510,80},{0, 733}, new sf::Sprite (*getTexture("sprites/ground.png"))); // Chão
    addThing(p);
    p = new Platform({1150,10},{300, 620}); // Platforma branca
    addThing(p);


    Obstacle* o;
    o = new Wall({50,10},{220,670}, sf::Color::Cyan);
    addObstacle(o);
    o = new Fire({130,675}, 25);
    addObstacle(o);
    o = new Black_Hole({500,650}, 40);
    addObstacle(o);

    /* Bordas do mapa */
    o = new Wall({10,800},{0,0}, sf::Color::Black);
    addObstacle(o);
    o = new Wall({10,800},{1500,0}, sf::Color::Black);
    addObstacle(o);

    Enemy* e;
    e = new Zombie({182,600});
    addCharacter(e);
    e = new Hell_Demon({500,540});
    addCharacter(e);
    e = new Hell_Demon({550,540});
    addCharacter(e);
    e = new Dressed_Zombie({800,540});
    addCharacter(e);
    e = new Dressed_Zombie({830,540});
    addCharacter(e);
    e = new Hell_Demon({1200,540});
    addCharacter(e);
    e = new Dressed_Zombie({1300,540});
    addCharacter(e);

    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background1.png")){
        std::cerr << "Erro ao ler background..." << std::endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition({0,300});

    Music* background_music = new Music("songs/city_theme.ogg");
    background_music->run();
}
City::~City(){}

sf::Vector2f City::getSpawnPoint(){
    return {50, 600};
}