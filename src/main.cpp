#include "includes.hpp"
#include "Object.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "Engine.hpp"
#include "Enemy.hpp"

int main(){

    sf::RenderWindow window;
    sf::View view(sf::FloatRect(0.f, 300.f, 600.f, 500.f));


    World w1;


    Engine engine(window,view);
    Player player(view);


    new Enemy({150,650});

    sf::Texture texture;
    if (!texture.loadFromFile("sprites/bg.png")){
        cerr << "Erro ao ler arquivo..." << endl;
    }

    texture.setSmooth(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    w1.setBackground(&sprite);
    engine.setWorld(&w1);

    engine.update();
    return 0;
}
