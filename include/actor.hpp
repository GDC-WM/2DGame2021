#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <SFML/Graphics.hpp>

#include "glob.hpp"


/**
 * An astranomical body
 */
class Actor {
public:
	Actor(const glob::vect &pos);

	const glob::vect &get_pos() { return _pos; };

	void get_velocity(const glob::vect &v) { _velocity = v; };

	virtual void update() { _pos += _velocity * glob::pdt.count() / 1000; };

	virtual void draw(sf::RenderWindow &window) {};

	int priority = 0;


private:
	glob::vect _pos;
	glob::vect _velocity;
};


#endif
