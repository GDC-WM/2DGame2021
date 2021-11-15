#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "glob.hpp"

#include <SFML/Graphics.hpp>

/**
 * Superclass for all objects in the game
 */
class Entity {
public:
	/**
	 * @param pos center point of the actor
	 * @param size dimensions of the actor (defaults to 0, 0)
	 */
	Entity(const glob::vect &pos, const glob::vect &size = {0, 0}) : _pos(pos), _size(size){};

	const glob::vect &get_pos() { return _pos; };

	const glob::vect &get_size() { return _size; };

	const glob::vect &get_velocity() { return _velocity; };

	const void set_pos(const glob::vect &v) { _pos = v; }

	const void set_size(const glob::vect &v) { _size = v; }

	const void set_velocity(const glob::vect &v) { _velocity = v; }

	/**
	 * @return true if the point falls within this entity
	 */
	virtual bool collides(const glob::vect &point) const { return false; };

	/**
	 * @return true if the entities overlap
	 */
	virtual bool collides(const Entity &) const { return false; };

	virtual void update(){/*_pos += _velocity * glob::dt;*/};

	virtual void draw(sf::RenderWindow &){};

	int priority = 0;

protected:
	glob::vect _pos, _size, _velocity{0, 0};
};

#endif
