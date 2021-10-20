#include <memory>
#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "actor.hpp"


void UserView::draw(sf::RenderWindow &w) {
	// draw actors
	for (auto actor : *_actors) actor->draw(w);
}


void UserView::handle_event(const sf::Event &e) {
	switch (e.type) {
		// TODO: do stuff here
		default:; // ignore other events
	}
}
