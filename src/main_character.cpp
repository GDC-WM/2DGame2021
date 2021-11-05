#include "entity.hpp"
#include "character.hpp"
#include "main_character.hpp"
#include "sprite_sheet.hpp"


MainCharacter::MainCharacter(const glob::vect &pos) : Character(pos, { 30, 30 }) {
	_sprite_sheet.set_loop(_walking);
	_speed = 200;
}


void MainCharacter::draw(sf::RenderWindow &w) {
	_sprite_sheet.set_pos(_pos);
	w.draw(_sprite_sheet.get_sprite());
}
