#ifndef MAIN_CHARACTER_HPP
#define MAIN_CHARACTER_HPP

#include "actor.hpp"
#include "character.hpp"

#include "sprite_sheet.hpp"


class MainCharacter : public Character {
public:
	MainCharacter(const glob::vect &pos);

	void draw(sf::RenderWindow &) override;


private:
	SpriteSheet _sprite_sheet { "../resources/cannon-barrel.png", 64 };
	Loop _walking { 0, 18, 40 };
};


#endif
