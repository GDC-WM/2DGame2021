#include "entity.hpp"
#include "missile.hpp"
#include "glob.hpp"

void Missile::update() {
	_velocity *= this->acceleration;
	switch (_steer_dir) {
		case glob::Rot::clockwise:
			_orientation = _velocity.angle() - this->steer_speed;
			break;
		case glob::Rot::counterclockwise:
			_orientation = _velocity.angle() + this->steer_speed;
			break;
		default:
			Entity::update();
			return;
	}
	_velocity.set_angle(_orientation);
	Entity::update();
}


void Missile::draw(sf::RenderWindow &w) {
	_sprite_sheet.set_pos(_pos);
  _sprite_sheet.set_orientation(_orientation);
	w.draw(_sprite_sheet.get_sprite());
}
