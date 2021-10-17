#include <memory>
#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "actor.hpp"


void UserView::draw(sf::RenderWindow &w) {
	// clear screen
	w.clear(sf::Color::Black);

	// draw actors
	for (auto actor : *_actors) actor->draw(w);

	// display screen
	w.display();
}


void UserView::handle_event(const sf::Event &e) {
	switch (e.type) {
		default:; // ignore other events
	}
}


void UserView::update() {
}
