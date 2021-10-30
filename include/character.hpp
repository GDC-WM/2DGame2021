#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "actor.hpp"

class Character : public Actor {
public:
	Character(const glob::vect &pos, const glob::vect &size) : Actor(pos), _size(size) {};
	void set_direction(const float &d) {_direction = d;}; // d stands for direction

protected:
	float _direction;
	float speed;
	glob::vect _size;
};

#endif