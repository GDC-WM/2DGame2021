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

/*
* Adds an actor to into StatePlaying._actors
*
*/
void StatePlaying::add_actor(std::shared_ptr<Actor> a) {
	// insert according to actor priority
	_actors->insert(std::lower_bound(_actors->begin(), _actors->end(), a,
			[](auto a1, auto a2) -> bool { return a1->priority < a2->priority; }), a);
};

/*
* Game Controller intercepts event and delegates it to the current State's handle_event 
* function. This means, if the game is in StatePlaying state, Game Controller sends 
* the events to the function below. 
*/
void StatePlaying::handle_event(const sf::Event &e) {
	switch (e.type) {
		// TODO: handle some stuff here (e.g. pause key clicked)
		default:
			_user_view->handle_event(e); // pass all other events to user view
	}
}

/*
* Game Controller issues the current state to update every frame. This menas, 
* if the game is in StatePlaying state, the function below gets called every 
* frame
*/
void StatePlaying::update() {
	for (auto view : *_views) view->update(); 
	for (auto actor : *_actors) actor->update();
}
