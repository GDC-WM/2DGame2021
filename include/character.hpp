#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "actor.hpp"
#include "glob.hpp"


class Character : public Actor {
public:
	Character(const glob::vect &pos, const glob::vect &size = { 0, 0 })
			: Actor(pos, size) {};

	/**
	 * @param d the new direction of movement in radians
	 */
	void set_direction(const float &d);


protected:
	float _speed; // speed of movement of the actor
};


#endif
