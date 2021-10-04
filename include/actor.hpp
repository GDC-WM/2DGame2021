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

	const glob::vect &pos() { return _pos; };

	void velocity(const glob::vect &v) { _velocity = v; };

	virtual void update() { _pos += _velocity * glob::pdt.count() / 1000; };

	virtual void draw(sf::RenderWindow &window) {};


private:
	glob::vect _pos;
	glob::vect _velocity;

	sf::CircleShape _drawable;
};


#endif
