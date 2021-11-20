#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entity.hpp"
#include "glob.hpp"
#include "sprite_sheet.hpp"

#include <chrono>

class Enemy : public Entity {
public:
	Enemy(const glob::vect &pos, const float &orientation);

	void adjust(const glob::Rot &di) { _steer_dir = dir; };

	void update() override;

	void draw(sf::RenderWindow &) override




}