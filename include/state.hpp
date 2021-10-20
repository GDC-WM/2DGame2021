#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class StateController;


/*
 * A state of the game
 */
class State {
public:
	State(std::shared_ptr<StateController> sc) : _state_controller(sc) {};

	virtual void draw(sf::RenderWindow &) const = 0;

	virtual void handle_event(const sf::Event &) = 0;

	virtual void update() = 0;

protected:
	std::shared_ptr<StateController> _state_controller;
};


#endif
