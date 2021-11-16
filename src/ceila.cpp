#include "ceila.hpp"

#include "character.hpp"
#include "sprite_sheet.hpp"

#include <iostream>
#include <math.h>

/**
 * @brief Construct a new Main Character:: Main Character object
 * Has default velocity of <30, 30>
 * @param pos Position to set Ceila to
 */
Ceila::Ceila(const glob::vect &pos) : Character(pos, {30, 30}) {
	_sprite_sheet.set_loop(_walking);
	_speed = 500;
}

void Ceila::draw(sf::RenderWindow &w) {
	_sprite_sheet.set_pos(_pos);
	w.draw(_sprite_sheet.get_sprite());
}