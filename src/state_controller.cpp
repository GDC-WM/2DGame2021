#include "state_controller.hpp"

#include "state.hpp"

StateController::StateController() {
	// set view position so (0, 0) is at the bottom left of the view
	sf::View view = _window.getView();
	view.move(0, -view.getSize().y);
	_window.setView(view);
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
