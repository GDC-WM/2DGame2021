#include "state_controller.hpp"
#include "state_menu.hpp"


StateController::StateController() {
	// instantiate to title
	_window = std::make_unique<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "Best game", sf::Style::Titlebar | sf::Style::Close);
}


void StateController::update() {
	if (_states.empty()) _running = false;

	_states.top()->update();

	// draw frame
	_window->clear(sf::Color::Black);
	_states.top()->draw(*_window);
	_window->display();

	// poll events
	sf::Event event;
	while (_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			_window->close();
			_running = false;
			return;
		}
		_states.top()->handle_event(event);
	}
}
