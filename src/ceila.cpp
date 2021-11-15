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

void Ceila::update() {
	glob::vect unitDirVectors(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
	    || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		unitDirVectors += glob::vect(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
	    || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		unitDirVectors += glob::vect(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
	    || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		unitDirVectors += glob::vect(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
	    || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		unitDirVectors += glob::vect(1, 0);
	}
	this->set_velocity(glob::normalize(unitDirVectors) * _speed);
	Entity::update();
}
void Ceila::draw(sf::RenderWindow &w) {
	_sprite_sheet.set_pos(_pos);
	w.draw(_sprite_sheet.get_sprite());
}