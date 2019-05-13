#pragma once

class Character
{
    public:
        Character();
        ~Character();

    protected:
    int vida;
    int score;
    float moveSpeed;
    bool isJumping;
    float jumpHeight;
    float finalJumpHeight;
    float maxSlideX;
    float maxSlideY;
    sf::Vector2f velocity;

    private:

};
