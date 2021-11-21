#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class StateController;

/*
 * A state of the game
 */
class State {
public:
	/**
	 * @param sc The state controller (used to allows a state to add or remove
	 * states from the state stack)
	 */
	State(std::shared_ptr<StateController> sc) : _state_controller(sc){};

	virtual void draw(sf::RenderWindow &) = 0;

	virtual void handle_event(const sf::Event &) = 0;

	virtual void update() = 0;

protected:
	std::shared_ptr<StateController> _state_controller;
};

#endif
