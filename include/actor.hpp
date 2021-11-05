#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <SFML/Graphics.hpp>

#include "glob.hpp"


/**
 * Superclass for all objects in the game
 */
class Actor {
public:
	Actor(const glob::vect &pos, const glob::vect &size = { 0, 0 })
			: _pos(pos), _size(size) {};

	const glob::vect &get_pos() { return _pos; };

	const glob::vect &get_size() { return _size; };

	virtual void update() { _pos += _velocity * glob::dt; };

	virtual void draw(sf::RenderWindow &) {};

	int priority = 0;


protected:
	glob::vect _pos, _size, _velocity;
};


#endif
