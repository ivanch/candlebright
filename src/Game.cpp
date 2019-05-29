#include "Main.hpp"

Main::Main():
    view(sf::FloatRect(0.f, 300.f, 600.f, 500.f)){
}
Main::~Main(){}

void Main::run(){
    Engine engine(window,view);
    Player player(view);

    new Enemy({150,650});
    new Enemy({250,550});

    if (!backgroundTexture.loadFromFile("sprites/bg.png")){
        cerr << "Erro ao ler background..." << endl;
    }

    backgroundTexture.setSmooth(true);
    background.setTexture(backgroundTexture);

    w1.setBackground(&background);
    engine.setWorld(&w1);

    engine.update();
}