#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "entity.hpp"
#include "glob.hpp"
#include "sprite_sheet.hpp"

#include <chrono>

/**
 * A steerable missile that accelerates and after a fuse times out, explodes
 */
class Missile : public Entity {
public:
	/**
	 * @param pos Vector center point of the missile
	 * @param orientation Sets the orientation and direction of movement of the
	 * missile
	 */
	Missile(const glob::vect &pos, const float &orientation);

	/**
	 * @param dir The rotational direction of movement
	 */
	void turn(const glob::Rot &dir) { _steer_dir = dir; };

	/**
	 * Check fuse, accelerate, and steer the missile
	 */
	void update() override;

	/**
	 * Draw missile on the RenderWindow
	 *
	 * @param RenderWindow RenderWindow to draw to
	 */
	void draw(sf::RenderWindow &) override;

	static constexpr float acceleration = 5;              // m/s^2
	static constexpr float steer_speed = 1.2;             // rad/s
	static constexpr auto fuse = std::chrono::seconds(2); // s

private:
	std::chrono::steady_clock::time_point _start_time;
	glob::Rot _steer_dir = glob::Rot::none;

	SpriteSheet _sprite_sheet{"../resources/cannon-barrel.png", 64};
	Loop _cruising{0, 18, 40};
};

#endif
