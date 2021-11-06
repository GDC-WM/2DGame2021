#include "state_controller.hpp"
#include "state.hpp"


StateController::StateController() {
	// instantiate to title
	_window = std::make_unique<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "Best game", sf::Style::Titlebar | sf::Style::Close);
}


void StateController::update() {
	if (_states.empty()) {
		_running = false;
		return;
	}

	_states.top()->update();

	// draw frame
	_window->clear(sf::Color::Black);
	_states.top()->draw(*_window);
	_window->display();

	// poll events
	sf::Event ev;
	while (_window->pollEvent(ev)) {
		if (ev.type == sf::Event::Closed) {
			_window->close();
			_running = false;
			return;
		}
		_states.top()->handle_event(ev);
	}
}
