#include <list>
#include <memory>
#include <algorithm>

#include "state_playing.hpp"
#include "view.hpp"
#include "actor.hpp"

#include <iostream>
StatePlaying::StatePlaying() {
	std::cout << "stateplaying constructor calld" << std::endl; 
	
	_actors = std::make_shared<std::list<std::shared_ptr<Actor>>>();
	_views = std::make_shared<std::list<std::shared_ptr<View>>>();
	_user_view = std::make_shared<UserView>(_actors); 
}

std::shared_ptr<State>  StatePlaying::handle_event(const sf::Event &e) {
	switch (e.type) {
		// TODO: handle some stuff here (e.g. pause key clicked)
		default:
			_user_view->handle_event(e); // pass all other events to user view
	}

	return NULL; 
}


std::shared_ptr<State> StatePlaying::update() {
	for (auto view : *_views) view->update();
	for (auto actor : *_actors) actor->update();
	return NULL;
}

