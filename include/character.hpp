#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "entity.hpp"
#include "glob.hpp"

/**
 * @brief Is an Entity.
 *
 */
class Character : public Entity {
public:
	Character(const glob::vect &pos, const glob::vect &size = {0, 0}) : Entity(pos, size){};

	/**
	 * @param v the vector to set the direction in, this v will be normalized to ensure
	 * the distance travelled by character is always the same
	 */
	void set_direction(const glob::vect &v);

	void set_speed(float v) { _speed = v; };

	const float get_speed() const { return _speed; }

protected:
	float _speed; // speed of movement of the entity
	glob::Allegiance allegiance; //the side the character is on
};

#endif
