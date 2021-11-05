#include <list>
#include <memory>
#include <algorithm>

#include "state_playing.hpp"
#include "view.hpp"
#include "entity.hpp"


StatePlaying::StatePlaying(std::shared_ptr<StateController> sc) : State(sc) {
	_entities = std::make_shared<std::list<std::shared_ptr<Entity>>>();
	_views = std::make_shared<std::list<std::shared_ptr<View>>>();
	_user_view = std::make_shared<UserView>(_entities);
}


void StatePlaying::add_entity(std::shared_ptr<Entity> a) {
	// insert according to entity priority
	_entities->insert(std::lower_bound(_entities->begin(), _entities->end(), a,
			[](auto a1, auto a2) -> bool { return a1->priority < a2->priority; }), a);
};


void StatePlaying::handle_event(const sf::Event &e) {
	switch (e.type) {
		// TODO: handle some stuff here (e.g. pause key clicked)
		default:
			_user_view->handle_event(e); // pass all other events to user view
	}
}


void StatePlaying::update() {
	for (auto view : *_views) view->update(); 
	for (auto entity : *_entities) entity->update();
}
