#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "entity.hpp"
#include "glob.hpp"


class Character : public Entity {
public:
	Character(const glob::vect &pos, const glob::vect &size = { 0, 0 })
			: Entity(pos, size) {};

	/**
	 * @param d the new direction of movement in radians
	 */
	void set_direction(const float &d);


protected:
	float _speed; // speed of movement of the entity
};


#endif
