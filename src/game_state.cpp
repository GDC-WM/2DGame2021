#include <list>
#include <memory>

#include "game_state.hpp"
#include "view.hpp"
#include "actor.hpp"


GameState::GameState() {
	_actors = std::make_shared<std::list<std::shared_ptr<Actor>>>();
	_views = std::make_shared<std::list<std::shared_ptr<View>>>();
}


void GameState::update() {
	for (auto view : *_views) view->update();
	for (auto actor : *_actors) actor->update();
}
