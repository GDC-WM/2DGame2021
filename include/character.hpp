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
	 * @param v the vector to set the direction in
	 */
	void set_direction(const glob::vect &v){};

protected:
	float _speed; // speed of movement of the entity
};

#endif
