#ifndef CELIA_HPP
#define CELIA_HPP

#include "character.hpp"
#include "sprite_sheet.hpp"

/**
 * Class for the main character
 */
class Celia : public Character {
public:
	/**
	 * @param pos Vector center point of Celia
	 */
	Celia(const glob::vect &pos);

	/**
	 * Draw Celia on the RenderWindow
	 *
	 * @param RenderWindow RenderWindow to draw to
	 */
	void draw(sf::RenderWindow &);

private:
	SpriteSheet _sprite_sheet{"../resources/cannon-barrel.png", 64};
	Loop _walking{0, 18, 40};
};

#endif
