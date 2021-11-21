#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "entity.hpp"
#include "glob.hpp"

#include <cmath>

/**
 * An Entity that is a character in the game. Characters have inventories and
 * are capable of creating dialog.
 */
class Character : public Entity {
public:
	/**
	 * @param pos Vector center point of the character
	 * @param size Vector dimensions of the character (defaults to 0, 0)
	 */
	Character(const glob::vect &pos, const glob::vect &size = {0, 0}) : Entity(pos, size){};

	/**
	 * @param d New direction of movement of the character in radians
	 */
	void set_direction(const float &d) {
		_velocity = {std::cos(d) * _speed, std::sin(d) * _speed};
	};

	/**
	 * @param v New vector velocity of the character -- magnitude will be
	 * adjusted to the speed of the character
	 */
	void set_direction(const glob::vect &v) { _velocity = glob::normalize(v) * get_speed(); };

	void set_speed(float v) { _speed = v; };

	const float get_speed() const { return _speed; }

protected:
	float _speed; // speed of movement of the entity
};

#endif
