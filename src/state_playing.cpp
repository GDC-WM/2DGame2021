#include <list>
#include <memory>
#include <algorithm>

#include "state_playing.hpp"
#include "view.hpp"
#include "actor.hpp"


StatePlaying::StatePlaying(std::shared_ptr<StateController> sc) : State(sc) {
	_actors = std::make_shared<std::list<std::shared_ptr<Actor>>>();
	_views = std::make_shared<std::list<std::shared_ptr<View>>>();
	_user_view = std::make_shared<UserView>(_actors);
}


void StatePlaying::add_actor(std::shared_ptr<Actor> a) {
	// insert according to actor priority
	_actors->insert(std::lower_bound(_actors->begin(), _actors->end(), a,
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
	for (auto actor : *_actors) actor->update();
}
