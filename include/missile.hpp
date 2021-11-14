#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "entity.hpp"
#include "glob.hpp"
#include "sprite_sheet.hpp"

class Missile : public Entity {
public:
	Missile(const glob::vect &pos, const float &orientation);

	/**
	 * @param d the rotational direction of movement
	 */
	void turn(const glob::Rot &dir) { _steer_dir = dir; };

	void update() override;

	void draw(sf::RenderWindow &) override;

	static constexpr float acceleration = 5;
	static constexpr float steer_speed = 1.2; // radians per second

private:
	glob::Rot _steer_dir = glob::Rot::none;
	SpriteSheet _sprite_sheet{"../resources/cannon-barrel.png", 64};
	Loop _cruising{0, 18, 40};
};

#endif
