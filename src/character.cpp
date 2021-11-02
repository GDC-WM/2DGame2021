#include "character.hpp"
#include <cmath>
void Character::set_direction(const float &d) {

_velocity = {std::cos(d)*_speed, std::sin(d)*_speed};

// glob::velocity += 

}