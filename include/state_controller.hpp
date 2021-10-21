#ifndef STATE_CONTROLLER_HPP
#define STATE_CONTROLLER_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class State;


/*fields:
	state: StatePlaying | StateMenu | StatePause
methods:
	update // called by main loop
		1) polls event and calls state.handleEvent(event) with the event
			state.handleEvent
		2) calls state.update(), state.enter(), once we sense state.update() returns
		a different state, we can set state to new state and
		call state.enter() in the game controller
		3) calls state.draw  */
class StateController : public std::enable_shared_from_this<StateController> {
public:
	StateController();

	void set_state(std::shared_ptr<State> state) { _state = state; };

	const sf::RenderWindow &window() { return *_window; };

	const bool &running() { return _running; };

	/**
	 * handles close event, delegate other events to _state 
	 * calls _state->update and _state->draw
	 */
	void update();


private:
	std::shared_ptr<State> _state;
	std::unique_ptr<sf::RenderWindow> _window;
	bool _running = true;
};

#endif
