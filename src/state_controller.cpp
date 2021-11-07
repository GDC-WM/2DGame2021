#include "state_controller.hpp"
#include "state.hpp"
#include <iostream>


StateController::StateController() {
	sf::View view = _window.getView();
	view.move(0, -view.getSize().y);
	_window.setView(view);
	std::cout << _window.getView().getCenter().y << '\n';
}


void StateController::update() {
	if (_states.empty()) {
		_running = false;
		return;
	}

	_states.top()->update();

	// draw frame
	_window.clear(sf::Color::Black);
	_states.top()->draw(_window);
	_window.display();

	// poll events
	sf::Event ev;
	while (_window.pollEvent(ev)) {
		if (ev.type == sf::Event::Closed) {
			_window.close();
			_running = false;
			return;
		}
		_states.top()->handle_event(ev);
	}
}
