#include "Plataform.hpp"

Plataform::Plataform(sf::Vector2f _start, sf::Vector2f _end, sf::Color _col):
        rect({_end.x - _start.x, _end.y - _start.y}){
    rect.setPosition({_start.x,_start.y});
    rect.setFillColor(_col);
    start = _start;
    end = _end;
}
Plataform::~Plataform(){}

void Plataform::draw(sf::RenderWindow& window){
    //rect.setTexture(&texture); // <- Precisa definir a textura toda vez que atualizar.
    window.draw(rect);
}

sf::FloatRect Plataform::getRect(){
    return rect.getGlobalBounds();
}

void Plataform::setTexture(string filename){
    if(!texture.loadFromFile(filename)){
        cout << "Erro ao ler arquivo: " << filename << endl;
        return;
    }
    texture.setSmooth(true);
    texture.setRepeated(true);
    rect.setTexture(&texture);
    rect.setTextureRect({0,0,256,256});
}