#include "actor.hpp"

class MainCharacter: public Actor
{
private:
    /* data */
    sf::CircleShape mainShape; 
public:
    MainCharacter(/* args */);
    ~MainCharacter();
    void draw(sf::RenderWindow &window);
    void update(); 
};