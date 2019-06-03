#include "World1.hpp"
#include "TextureManager.hpp"

World_1::World_1(){
    Plataform* p;
    p = new Plataform({1280,30},{0,720}, TextureManager::grass); // Chão
    entities.entity_list.insertBack(static_cast<Entity*>(p));
    objects.push_back(static_cast<Object*>(p));
    p = new Plataform({1280,10},{150,625}); // Plataforma branca
    entities.entity_list.insertBack(static_cast<Entity*>(p));
    objects.push_back(static_cast<Object*>(p));
    p = new Plataform({1280,5},{200,550}, sf::Color::Red); // Plataforma vermelha
    p->setMoving(true);
    p->setMove({100,0});
    p->setMoveSpeed({0.5,0});
    entities.entity_list.insertBack(static_cast<Entity*>(p));
    objects.push_back(static_cast<Object*>(p));

    p = new Plataform({50,2},{-50,700}, sf::Color::Magenta); // Plataforma rosa
    p->setMoving(true);
    p->setMove({0,100});
    p->setMoveSpeed({0,0.5});
    entities.entity_list.insertBack(static_cast<Entity*>(p));
    objects.push_back(static_cast<Object*>(p));

    Obstacle* o;
    o = new Obstacle({10,50},{100,650}, sf::Color::Cyan);
    entities.entity_list.insertBack(static_cast<Entity*>(o));
    objects.push_back(static_cast<Object*>(o));
    o = new Obstacle({20,50},{50,500}, sf::Color::Cyan);
    entities.entity_list.insertBack(static_cast<Entity*>(o));
    objects.push_back(static_cast<Object*>(o));
    o = new Obstacle({20,50},{125,450}, sf::Color::Cyan);
    entities.entity_list.insertBack(static_cast<Entity*>(o));
    objects.push_back(static_cast<Object*>(o));

    Enemy* e;
    e = new Enemy_1({150,650});
    entities.entity_list.insertBack(static_cast<Entity*>(e));
    objects.push_back(static_cast<Object*>(e));
    e = new Enemy_1({250,550});
    entities.entity_list.insertBack(static_cast<Entity*>(e));
    objects.push_back(static_cast<Object*>(e));


    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background.png")){
        cerr << "Erro ao ler background..." << endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition({0,300});
}
World_1::~World_1(){}
