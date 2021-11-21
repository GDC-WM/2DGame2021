#ifndef STATE_CONTROLLER_HPP
#define STATE_CONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

class State;

/**
 * Manages states using a stack of states
 */
class StateController : public std::enable_shared_from_this<StateController> {
public:
	StateController();

	/**
	 * @return The state stack
	 */
	std::stack<std::shared_ptr<State>> &states() { return _states; };

	/**
	 * @return The render window
	 */
	const sf::RenderWindow &window() { return _window; };

	/**
	 * @return whether the game is running
	 */
	const bool &running() { return _running; };

	/**
	 * Handles close event, delegate other events to the current state
	 * Calls _state->update and _state->draw
	 */
	void update();

private:
	std::stack<std::shared_ptr<State>> _states;
	bool _running = true;
	sf::RenderWindow _window{sf::VideoMode(1280, 720, 32), "Best game",
	                         sf::Style::Titlebar | sf::Style::Close};
};

#endif
