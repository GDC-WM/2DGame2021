#include "state_menu.hpp"
#include <iostream> 

void StateMenu::draw(sf::RenderWindow &window) const{
    // window.draw button
    sf::CircleShape circle(50); 
    circle.setFillColor(sf::Color::Red); 
    circle.setPosition(sf::Vector2f(100, 100)); 


    std::cout << 33 << std::endl; 
    sf::Text text;
    text.setString("Hello world");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);
    window.draw(circle); 
}

std::shared_ptr<State> StateMenu::handle_event(const sf::Event &e){
    switch(e.type){
        // if clicked on play button then return state playing
    
        default: return NULL; 
    }
}

std::shared_ptr<State> StateMenu::update() {
    // nothing really updates 
	return NULL;
}
