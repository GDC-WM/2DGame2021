#include <list>
#include <memory>
#include <algorithm>

#include "game_state.hpp"
#include "actor.hpp"


void GameState::add_actor(std::shared_ptr<Actor> a) {
	// insert accorting to actor priority
	_actors->insert(std::lower_bound(_actors->begin(), _actors->end(), a,
			[](auto a1, auto a2) -> bool { return a1->priority < a2->priority; }), a);
};
