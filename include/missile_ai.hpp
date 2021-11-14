#ifndef MISSILE_AI_HPP
#define MISSILE_AI_HPP

#include "entity.hpp"
#include "missile.hpp"
#include "view.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class MissileAI : public View {
public:
	MissileAI(const std::shared_ptr<std::list<std::shared_ptr<Entity>>> &entities,
	          std::shared_ptr<Missile> missile, std::shared_ptr<Entity> target)
			: View(entities), _missile(missile), _target(target){};

	void update() override;

private:
	std::shared_ptr<Missile> _missile;
	std::shared_ptr<Entity> _target;
};

#endif
