#include "state_menu.hpp"

#include "button.hpp"
#include "state.hpp"
#include "state_controller.hpp"
#include "state_playing.hpp"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <memory>

StateMenu::StateMenu(std::shared_ptr<StateController> sc) : State(sc) {
	_title_text.setString("Start playing");
	_title_text.setCharacterSize(100);
	_title_text.setPosition(350, -600);
	_title_text.setFillColor(sf::Color::Red);

	if (_font.loadFromFile("../fonts/arial.ttf")) _title_text.setFont(_font);
	else std::cout << "can't load font" << std::endl;
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
		glob::vect mouse_pos
				= glob::convert_vect(sf::Mouse::getPosition(_state_controller->window()));
		// account for view offset
		mouse_pos.y += _state_controller->window().getView().getSize().y;

		// check play button clicked
		if (play_button.collides(mouse_pos)) {
			_state_controller->states().push(std::make_shared<StatePlaying>(_state_controller));
		}
		break;
	}
	default:;
	}
}
