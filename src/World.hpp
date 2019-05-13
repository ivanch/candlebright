class World{
    private:
        vector<Plataform> plataforms;
        vector<Object*> objects;

    public:
        World(){
            Plataform p1({0,700},{1280,710}, sf::Color::Green);
            plataforms.push_back(p1);
        }
        ~World(){}

        void draw(sf::RenderWindow& window){
            for(auto itr = plataforms.begin(); itr != plataforms.end(); ++itr){
                itr->draw(window);
            }
        }

        void addObject(Object* o){
            objects.push_back(o);
        }

        void gravity(){
            for(auto itr = objects.begin(); itr != objects.end(); ++itr){
                if(!isColliding((*itr)->getRect())){
                    (*itr)->fall();
                }
            }
        }

        bool isColliding(sf::FloatRect rect){
            for(auto itr = plataforms.begin(); itr != plataforms.end(); ++itr){
                sf::FloatRect p_rect = itr->getRect();
                if(p_rect.intersects(rect)) return true;
            }
            return false;
        }
};