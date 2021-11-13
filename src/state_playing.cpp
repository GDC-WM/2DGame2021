#include <list>
#include <memory>
#include <algorithm>

#include "state.hpp"
#include "state_playing.hpp"
#include "state_controller.hpp"
#include "view.hpp"
#include "entity.hpp"
#include <iostream>

StatePlaying::StatePlaying(std::shared_ptr<StateController> sc) : State(sc)
{
	_entities = std::make_shared<std::list<std::shared_ptr<Entity>>>();
	_views = std::make_shared<std::list<std::shared_ptr<View>>>();

	// add main character
	_main_character = std::make_shared<MainCharacter>(glob::vect(100, 100));
	_main_character->set_direction(1);
	this->add_entity(_main_character);
}

void StatePlaying::add_entity(std::shared_ptr<Entity> e)
{
	// insert according to entity priority
	_entities->insert(std::lower_bound(_entities->begin(), _entities->end(), e,
									   [](auto a1, auto a2) -> bool
									   { return a1->priority < a2->priority; }),
					  e);
};

void StatePlaying::handle_event(const sf::Event &ev)
{
}

void StatePlaying::draw(sf::RenderWindow &w)
{
	for (auto entity : *_entities)
		entity->draw(w);
}

void StatePlaying::update()
{
	for (auto view : *_views)
		view->update();
	for (auto entity : *_entities)
		entity->update();
}
