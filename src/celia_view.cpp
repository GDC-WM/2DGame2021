#include "celia_view.hpp"

#include "celia.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

void CeliaView::update() {
	// set movement direction based on keyboard input
	glob::vect new_dir(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		new_dir += glob::vect(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		new_dir += glob::vect(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		new_dir += glob::vect(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		new_dir += glob::vect(1, 0);
	}
	_celia->set_direction(new_dir);
}
