#include <list>
#include <memory>
#include <algorithm>

#include "game_state.hpp"
#include "view.hpp"
#include "actor.hpp"


GameState::GameState() {
	_actors = std::make_shared<std::list<std::shared_ptr<Actor>>>();
	_views = std::make_shared<std::list<std::shared_ptr<View>>>();
}


void GameState::add_actor(std::shared_ptr<Actor> a) {
	// insert according to actor priority
	_actors->insert(std::lower_bound(_actors->begin(), _actors->end(), a,
			[](auto a1, auto a2) -> bool { return a1->priority < a2->priority; }), a);
};


void GameState::update() {
	for (auto view : *_views) view->update();
	for (auto actor : *_actors) actor->update();
}
