#include <memory>
#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "game_state.hpp"
#include "actor.hpp"


UserView::UserView(std::shared_ptr<GameState> game_state)
		: _game_state(game_state), View(game_state->get_actors()) {
}


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
