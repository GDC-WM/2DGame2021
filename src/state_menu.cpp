#include <memory>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "state_menu.hpp"
#include "state_controller.hpp"
#include "state_playing.hpp"
#include "button.hpp"


StateMenu::StateMenu(std::shared_ptr<StateController> sc) : State(sc) {
	_title_text.setString("Start playing");
	_title_text.setCharacterSize(100);
	_title_text.setPosition(350, -600);
	_title_text.setFillColor(sf::Color::Red);

	if (!font.loadFromFile("../fonts/arial.ttf"))
		std::cout << "can't load font" << std::endl;
	else _title_text.setFont(font);
}


void StateMenu::draw(sf::RenderWindow &w) {
	play_button.draw(w);
	w.draw(_title_text);
}


void StateMenu::handle_event(const sf::Event &ev) {
	switch (ev.type) {
		// play button switches state playing
		case sf::Event::MouseButtonPressed: {
			// get mouse position
			glob::vect mouse_pos = glob::convert_vect(sf::Mouse::getPosition(
					_state_controller->window()));
			// account for view offset
			mouse_pos.y += _state_controller->window().getView().getSize().y;

			// check play button clicked
			if (play_button.collides(mouse_pos)) {
				_state_controller->states().push(
						std::make_shared<StatePlaying>(_state_controller));
			}
			break;
		}
		default:;
	}
}
