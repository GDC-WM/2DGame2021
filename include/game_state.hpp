#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <list>
#include <memory>

class View;
class Actor;


/*
 * A state of the game (grouping of the views and model)
 */
class GameState {
public:
	GameState();

	/**
	 * @return the list of actors.
	 */
	const auto &get_actors() const { return _actors; };

	void add_actor(std::shared_ptr<Actor> a) { _actors->push_back(a); };

	/**
	 * @return the list of views.
	 */
	const auto &get_views() const { return _views; };

	void add_view(std::shared_ptr<View> v) { _views->push_back(v); };

	void update();


private:
	std::shared_ptr<std::list<std::shared_ptr<View>>> _views;
	std::shared_ptr<std::list<std::shared_ptr<Actor>>> _actors;
};


#endif
