#include "Enemy.hpp"

Enemy::Enemy(sf::View& _view, string _name):
        view(_view), name(_name){

    enemy.setSize({20,30});
    enemy.setFillColor(sf::Color::Red);
    setPos({170, 670});
    world = NULL;
    vida = 100;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    isJumping = false;
    mRight = false;
    originalPos = (enemy.getPosition());
    finalJumpHeight = 0;
    Listener::listeners.push_back(dynamic_cast<Listener*>(this));
}
void Enemy::move(sf::Vector2f vec){
    enemy.move(vec);
    if(enemy.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  > -50   && vec.x > 0)
        view.move({vec.x,0});
    if(enemy.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  < -550  && vec.x < 0)
        view.move({vec.x,0});
}
void Enemy::setPos(sf::Vector2f newPos) {
    enemy.setPosition(newPos);
}
void Enemy::drawTo(sf::RenderWindow &window) {
    window.draw(enemy);
}
sf::FloatRect Enemy::getRect(){
    return enemy.getGlobalBounds();
}
void Enemy::debug(){
    cout << world->intersectsUp(getRect()) << ", " << world->intersectsDown(getRect()) << ", "
         << world->intersectsLeft(getRect()) << ", " << world->intersectsRight(getRect()) << ", "
         << isJumping << ", " << endl;
}
void Enemy::fall(){
    if(!isJumping){
        move({0,2.50});
    }
}
void Enemy::moveRight(){
    move({moveSpeed,0});
}
void Enemy::moveLeft(){
    move({-moveSpeed,0});
}
void Enemy::onUpdate(){

    sf::Vector2f pos = enemy.getPosition();

     if(mRight){
            if(!world->intersectsLeft(getRect()))
                enemy.move({-moveSpeed,0});
            else
                mRight=false;
            if(abs(pos.x) < abs(originalPos.x-100)) mRight = false;
        }else{
            if(!world->intersectsRight(getRect()))
                enemy.move({moveSpeed,0});
            else
                mRight=true;
            if(abs(pos.x) > abs(originalPos.x+100)) mRight = true;
        }
    if(world->intersectsUp(getRect())){
        velocity.y = 0;
        isJumping = false;
    }


}
