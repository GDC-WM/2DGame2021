#include "ceila_view.hpp"

void CeilaView::draw(sf::RenderWindow &w) {
	// draw entities
	for (auto entity : *_entities) entity->draw(w);
}

void CeilaView::handle_event(const sf::Event &e) {
	glob::vect dirVectors(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		dirVectors += glob::vect(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		dirVectors += glob::vect(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		dirVectors += glob::vect(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		dirVectors += glob::vect(1, 0);
	}
	glob::vect curPos = _ceila->get_pos();
	// Must normalize so the distance the actor travels is equalled to the magnitude of speed
	glob::vect velocity = glob::normalize(dirVectors) * _ceila->get_speed();
	_ceila->set_pos(curPos + velocity * glob::dt);
}