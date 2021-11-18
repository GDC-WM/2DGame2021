#include "missile_ai.hpp"

#include "entity.hpp"
#include "glob.hpp"
#include "missile.hpp"

void MissileAI::update() {
	float relative_angle
			= (_target->get_pos() - _missile->get_pos()).angle() - _missile->get_orientation();

	if (std::abs(std::sin(relative_angle)) < Missile::steer_speed * glob::dt) {
		_missile->turn(glob::Rot::none);
		return;
	}

	std::sin(relative_angle) > 0 ? _missile->turn(glob::Rot::counterclockwise)
	                             : _missile->turn(glob::Rot::clockwise);
}
