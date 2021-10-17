#include "state_menu.hpp"
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "state_playing.hpp"
StateMenu::StateMenu(){
    text.setString("Start playing big noob!");
    text.setCharacterSize(100); // in pixels, not points!
    text.setPosition(sf::Vector2f(200, 200)); 
    // set the color
    text.setFillColor(sf::Color::Red);

    if(!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cout << "can't load font" << std::endl;
    }else{
    text.setFont(font); 
    }
        

    }

void StateMenu::draw(sf::RenderWindow &window) const{
    // window.draw button
    sf::CircleShape circle(50); 
    circle.setFillColor(sf::Color::Red); 
    circle.setPosition(sf::Vector2f(100, 100)); 


    // set the character size
    

    window.draw(circle); 
    window.draw(text);  // TODO: this isn't working rn 
}

std::shared_ptr<State> StateMenu::handle_event(const sf::Event &e){
    
    switch(e.type){
        // if clicked on play button then return state playing
        case sf::Event::MouseButtonPressed: {
            // transition on click
            sf::Vector2i position = sf::Mouse::getPosition(); 
            int x = position.x; 
            int y = position.y; 
            std::cout << "x" << position.x <<"y"<<  position.y << std::endl; 
            std::cout << "should transition to new state!" << std::endl;
            std::shared_ptr<StatePlaying> woah = std::make_shared<StatePlaying>(); 
            return woah; 
          
            break; 
        }

        default:; 
    }

    return NULL; 
}

std::shared_ptr<State> StateMenu::update() {
    // nothing really updates 
	return NULL;
}
