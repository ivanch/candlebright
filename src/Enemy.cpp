#include "Enemy.hpp"

Enemy::Enemy(sf::View& _view, string _name):
        view(_view), name(_name){

    enemy.setSize({20,30});
    enemy.setFillColor(sf::Color::Red);
    setPos({170.0, 530});
    world = NULL;
    isJumping = false;
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
void Enemy::onUpdate(){

    if(world->intersectsUp(getRect())){
        velocity.y = 0;
        isJumping = false;
    }
}
