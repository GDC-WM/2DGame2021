#include "missile.hpp"

#include "entity.hpp"
#include "glob.hpp"

Missile::Missile(const glob::vect &pos, const float &orientation) : Entity(pos, {20, 5}) {
	_orientation = orientation;
	_sprite_sheet.set_loop(_cruising);
	_velocity = {10, 0};
};

void Missile::update() {
	_velocity += this->acceleration;
	switch (_steer_dir) {
	case glob::Rot::clockwise:
		_orientation -= this->steer_speed * glob::dt;
		break;
	case glob::Rot::counterclockwise:
		_orientation += this->steer_speed * glob::dt;
		break;
	default:
		break;
	}
	_velocity.set_angle(_orientation);
	Entity::update();
}

void Missile::draw(sf::RenderWindow &w) {
	_sprite_sheet.set_pos(_pos);
	_sprite_sheet.set_orientation(_orientation);
	w.draw(_sprite_sheet.get_sprite());
}
