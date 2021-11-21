#include "state_playing.hpp"

#include "celia.hpp"
#include "celia_view.hpp"
#include "entity.hpp"
#include "glob.hpp"
#include "missile.hpp"
#include "missile_ai.hpp"
#include "state.hpp"
#include "state_controller.hpp"
#include "view.hpp"

#include <algorithm>
#include <iostream>
#include <list>
#include <memory>

StatePlaying::StatePlaying(std::shared_ptr<StateController> sc) : State(sc) {
	_entities = std::make_shared<std::list<std::shared_ptr<Entity>>>();
	_views = std::make_shared<std::list<std::shared_ptr<View>>>();

	// add celia to list of entities
	std::shared_ptr<Celia> celia = std::make_shared<Celia>(glob::vect(100, 100));
	this->add_entity(celia);
	// add celia view to list of views
	_celia_view = std::make_shared<CeliaView>(_entities, celia);
	_views->emplace_back(_celia_view);

	// add a missile
	std::shared_ptr<Missile> missile = std::make_shared<Missile>(glob::vect(700, 200), glob::GLOB_PI);
	this->add_entity(missile);
	this->add_view(std::make_shared<MissileAI>(_entities, missile, celia));
}

void StatePlaying::add_entity(std::shared_ptr<Entity> e) {
	// insert according to entity priority
	_entities->insert(
			std::lower_bound(_entities->begin(), _entities->end(), e,
	                         [](auto a1, auto a2) -> bool { return a1->priority < a2->priority; }),
			e);
};

void StatePlaying::handle_event(const sf::Event &ev) {}

void StatePlaying::draw(sf::RenderWindow &w) {
	for (auto entity : *_entities) entity->draw(w);
}

void StatePlaying::update() {
	for (auto view : *_views) view->update();
	for (auto entity : *_entities) entity->update();
}
