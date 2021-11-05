#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "user_view.hpp"

class View;
class Actor;


/*
 * A state of the game
 */
class StatePlaying : public State {
public:
	StatePlaying(std::shared_ptr<StateController> sc);

	/**
	 * @return the list of actors.
	 */
	const auto &get_actors() const { return _actors; };

	// TODO: maybe move this method to glob
	void add_actor(std::shared_ptr<Actor> a);

	/**
	 * @return the list of views.
	 */
	const auto &get_views() const { return _views; };

	// TODO: maybe remove this method
	void add_view(std::shared_ptr<View> v) { _views->push_back(v); };

	void draw(sf::RenderWindow &w) const override { _user_view->draw(w); };

	/*
	 * Game Controller intercepts event and delegates it to the current State's handle_event 
	 * function. This means, if the game is in StatePlaying state, Game Controller sends 
	 * the events to the function below. 
	 */
	void handle_event(const sf::Event &) override;

	/*
	 * Game Controller issues the current state to update every frame. This means, 
	 * if the game is in StatePlaying state, the function below gets called every 
	 * frame
	 */
	void update() override;


private:
	std::shared_ptr<std::list<std::shared_ptr<View>>> _views;
	std::shared_ptr<std::list<std::shared_ptr<Actor>>> _actors;
	std::shared_ptr<UserView> _user_view;
};


#endif
