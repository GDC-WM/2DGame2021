#include <memory>
#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "entity.hpp"


void UserView::draw(sf::RenderWindow &w) {
	// draw entities
	for (auto entity : *_entities) entity->draw(w);
}


void UserView::handle_event(const sf::Event &e) {
	switch (e.type) {
		// TODO: do stuff here
		//case sf::Keyboard::W:
		default:; // ignore other events
	}
}
