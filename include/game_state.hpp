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
	auto actors() { return _actors; };

	/**
	 * @return the list of views.
	 */
	auto views() { return _views; };

	void update();


private:
	std::shared_ptr<std::list<std::shared_ptr<View>>> _views;
	std::shared_ptr<std::list<std::shared_ptr<Actor>>> _actors;
};


#endif
