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
	 * @param pos Vector center point of the entity
	 * @param size Vector dimensions of the entity (defaults to 0, 0)
	 */
	Entity(const glob::vect &pos, const glob::vect &size = {0, 0}) : _pos(pos), _size(size){};

	/**
	 * @return The vector position of the entity
	 */
	const glob::vect &get_pos() const { return _pos; };

	/**
	 * @return The vector dimensions of the entity
	 */
	const glob::vect &get_size() const { return _size; };

	/**
	 * @return The direction the entity is facing in radians
	 */
	const float &get_orientation() const { return _orientation; };

	/**
	 * @return The vector velocity of the entity
	 */
	const glob::vect &get_velocity() { return _velocity; };

	/**
	 * Detect a collision
	 *
	 * @param point Vector position to test
	 * @return True if the point falls within this entity
	 */
	virtual bool collides(const glob::vect &point) const { return false; };

	/**
	 * Detect a collision
	 *
	 * @param Entity Entity to test
	 * @return Whether the entities overlap
	 */
	virtual bool collides(const Entity &) const { return false; };

	/**
	 * Updates position based on velocity
	 */
	virtual void update() { _pos += _velocity * glob::dt; };

	/**
	 * Draw entity on the RenderWindow
	 *
	 * @param RenderWindow RenderWindow to draw to
	 */
	virtual void draw(sf::RenderWindow &){};

	int priority = 0;

protected:
	glob::vect _pos, _size, _velocity{0, 0};

	float _orientation = 0;
};

#endif
