#include <iostream>
#include <SFML/Graphics.hpp>

#include "state_controller.hpp"
#include "state_menu.hpp"
#include "state_playing.hpp"
#include "character.hpp"
#include "glob.hpp"


StateMenu::StateMenu(std::shared_ptr<StateController> sc) : State(sc) {
	text.setString("Start playing");
	text.setCharacterSize(100);
	text.setPosition(sf::Vector2f(200, 200));
	text.setFillColor(sf::Color::Red);

	if (!font.loadFromFile("../fonts/arial.ttf"))
		std::cout << "can't load font" << std::endl;
	else text.setFont(font);
}


void StateMenu::draw(sf::RenderWindow &window) const {
	// window.draw button
	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(100, 100));

	window.draw(circle);
	window.draw(text);
}


void StateMenu::handle_event(const sf::Event &e) {
	switch (e.type) {
		// play button switches state playing
		case sf::Event::MouseButtonPressed:
			// TODO: temporary crap, later use a button actor check collision
			// with the mouse pointer:
			if (sf::Mouse::getPosition(_state_controller->window()).x < 150)
			{
				std::shared_ptr<StatePlaying> new_state = std::make_shared<StatePlaying>(_state_controller);
				new_state->add_actor(std::make_shared<Character>(glob::vect(30,30), glob::vect(30,30)));
				_state_controller->states().push(new_state);
			}
			break;
		default:;
	}
}
