#include <list>
#include <memory>
#include <algorithm>

#include "state.hpp"
#include "state_playing.hpp"
#include "state_controller.hpp"
#include "view.hpp"
#include "user_view.hpp"
#include "entity.hpp"


StatePlaying::StatePlaying(std::shared_ptr<StateController> sc) : State(sc) {
	_entities = std::make_shared<std::list<std::shared_ptr<Entity>>>();
	_views = std::make_shared<std::list<std::shared_ptr<View>>>();

	// add user
	//TODO: this is maybe not the best way to do this long term, but it is the
	// simplest solution at the moment that gives StatePlaying direct access
	// to UserView so it can relay events
	std::shared_ptr<MainCharacter> mc = std::make_shared<MainCharacter>(glob::vect(100,100));
	mc->set_direction(1);
	_user_view = std::make_shared<UserView>(_entities, mc);
	this->add_entity(mc);
	_views->emplace_back(_user_view);
}


void StatePlaying::add_entity(std::shared_ptr<Entity> e) {
	// insert according to entity priority
	_entities->insert(std::lower_bound(_entities->begin(), _entities->end(), e,
			[](auto a1, auto a2) -> bool { return a1->priority < a2->priority; }), e);
};


void StatePlaying::handle_event(const sf::Event &ev) {
	switch (ev.type) {
		// TODO: handle some stuff here (e.g. pause key clicked)
		default:
			_user_view->handle_event(ev); // pass all other events to user view
	}
}


void StatePlaying::update() {
	for (auto view : *_views) view->update(); 
	for (auto entity : *_entities) entity->update();
}
