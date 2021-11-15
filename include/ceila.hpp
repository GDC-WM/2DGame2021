#ifndef CEILA_HPP
#define CEILA_HPP

#include "character.hpp"
#include "sprite_sheet.hpp"

/**
 * @brief Is a Character
 */
class Ceila : public Character {
public:
	Ceila(const glob::vect &pos);

	void draw(sf::RenderWindow &);

	void update();

	void move(const glob::vect &moveBy);

private:
	SpriteSheet _sprite_sheet{"../resources/cannon-barrel.png", 64};
	Loop _walking{0, 18, 40};
};

#endif