#ifndef STATE_CONTROLLER_HPP
#define STATE_CONTROLLER_HPP

#include <memory>
#include <stack>
#include <SFML/Graphics.hpp>

class State;


class StateController : public std::enable_shared_from_this<StateController> {
public:
	StateController();

	std::stack<std::shared_ptr<State>> &states() { return _states; };

	const sf::RenderWindow &window() { return *_window; };

	const bool &running() { return _running; };

	/**
	 * handles close event, delegate other events to _state 
	 * calls _state->update and _state->draw
	 */
	void update();


private:
	std::stack<std::shared_ptr<State>> _states;
	std::unique_ptr<sf::RenderWindow> _window;
	bool _running = true;
};

#endif
