#include "ceila_view.hpp"

void CeilaView::draw(sf::RenderWindow &w) {
	// draw entities
	for (auto entity : *_entities) entity->draw(w);
}

void CeilaView::update() {
	glob::vect dir_vectors(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		dir_vectors += glob::vect(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		dir_vectors += glob::vect(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		dir_vectors += glob::vect(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		dir_vectors += glob::vect(1, 0);
	}
	_ceila->set_direction(dir_vectors);
}