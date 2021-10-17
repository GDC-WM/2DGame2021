#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>


/*
 * A state of the game
 */
class State {
public:
	State();

	virtual void draw(sf::RenderWindow &) const = 0;

	virtual void handle_event(const sf::Event &) = 0;

	virtual std::shared_ptr<State> update() = 0;
};


#endif
