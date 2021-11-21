#include "celia.hpp"

#include "character.hpp"
#include "glob.hpp"
#include "sprite_sheet.hpp"

Celia::Celia(const glob::vect &pos) : Character(pos) {
	_size = glob::vect(30, 30);
	_speed = 500;
	_sprite_sheet.set_loop(_walking);
}

void Celia::draw(sf::RenderWindow &w) {
	_sprite_sheet.set_pos(_pos);
	w.draw(_sprite_sheet.get_sprite());
}
