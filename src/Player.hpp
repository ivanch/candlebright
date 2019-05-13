#pragma once

class Player: public Listener, public Object{
    private:
        string name;
        int score;
        float moveSpeed;
        bool isJumping;
        float jumpHeight;
        float maxVelocityX;
        float maxVelocityY;
        sf::Vector2f acc; // vetor de acelera��o

        sf::RectangleShape player;
        sf::View& view;

        World* world;

        void move(sf::Vector2f vec);
    public:
        Player(sf::View& _view, string _name = "");
        ~Player();

        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();
        void jump();
        void jumpFall();
        void onUpdate();
        void drawTo(sf::RenderWindow &window);
        void fall();
        sf::FloatRect getRect();

        void setWorld(World* _world){ world = _world; }
};
