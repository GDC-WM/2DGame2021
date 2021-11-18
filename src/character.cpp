#include "character.hpp"

#include "glob.hpp"

#include <cmath>

void Character::set_direction(const glob::vect &v) { _velocity = glob::normalize(v) * get_speed(); }