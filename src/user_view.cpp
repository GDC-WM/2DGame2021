#include <memory>
#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "game_state.hpp"
#include "actor.hpp"


UserView::UserView(std::shared_ptr<GameState> game_state)
		: _game_state(game_state), View(game_state->get_actors()) {
	// initialize window
	_window = std::make_unique<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "", sf::Style::Titlebar | sf::Style::Close);
}


void UserView::listen() {
	sf::Event event;
	while (_window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				_window->close();
				_running = false;
				break;
			default:; // ignore other events
		}
	}
}


void UserView::draw() {
	// clear screen
	_window->clear(sf::Color::Black);

	// draw actors
	for (auto actor : *_actors) actor->draw(*_window);

	// display screen
	_window->display();
}


void UserView::update() {
	this->listen();
}
