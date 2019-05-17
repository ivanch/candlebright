#include "Plataform.hpp"

vector<Plataform*> Plataform::plataforms;

Plataform::Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    plataforms.push_back(this);
    mRight = false;
    mUp = false;
    texture = NULL;
}
Plataform::Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    texture = _tex;
    rect.setPosition(pos);
    plataforms.push_back(this);
}
Plataform::~Plataform(){}

void Plataform::drawTo(sf::RenderWindow& window){
    window.draw(rect);
}

void Plataform::onUpdate(){
    if(moving){
        fmove();
    }
    if(texture != NULL) rect.setTexture(texture);
}

sf::FloatRect Plataform::getRect(){
    return rect.getGlobalBounds();
}

void Plataform::setMoveSpeed(sf::Vector2f _vel){
    vel = _vel;
}
void Plataform::setMove(sf::Vector2f _move){
    move = _move;
}
void Plataform::setMoving(bool _moving){
    moving = _moving;
    if(moving){
        Listener::listeners.push_back(dynamic_cast<Listener*>(this));
    }else{
        for(auto itr = Listener::listeners.begin(); itr != Listener::listeners.end(); ++itr)
            if(*itr == this){
                Listener::listeners.erase(itr);
                break;
            }
    }
}
void Plataform::fmove(){
    sf::Vector2f pos = rect.getPosition();
    if(mRight){
        moveChars({-vel.x,0});
        rect.move({-vel.x,0});
        if(abs(pos.x) < abs(originalPos.x-move.x)) mRight = false;
    }else{
        moveChars({vel.x,0});
        rect.move({vel.x,0});
        if(abs(pos.x) > abs(originalPos.x+move.x)) mRight = true;
    }
    if(mUp){
        moveChars({0,-vel.y});
        rect.move({0,-vel.y});
        if(abs(pos.y) < abs(move.y-originalPos.y)) mUp = false;
    }else{
        moveChars({0,vel.y});
        rect.move({0,vel.y});
        if(abs(pos.y) > abs(move.y+originalPos.y)) mUp = true;
    }
}

void Plataform::moveChars(sf::Vector2f _move){
    for(auto itr = Character::characters.begin(); itr != Character::characters.end(); ++itr){
        if(Intersect::intersectsUp(getRect(), (*itr)->getRect())){
            (*itr)->move(_move);
        }
    }
}
