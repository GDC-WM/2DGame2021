#include "character.hpp"

#include "glob.hpp"

void Character::set_direction(const float &d) {
	_velocity = {std::cos(d) * _speed, std::sin(d) * _speed};
}

void Character::set_direction(const glob::vect &v) { _velocity = glob::normalize(v) * get_speed(); }
