#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP

#include "main_character.hpp"
#include "state.hpp"
#include "view.hpp"

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

class View;
class Entity;
class StateController;

/*
 * A state of the game
 */
class StatePlaying : public State {
public:
	StatePlaying(std::shared_ptr<StateController>);

	/**
	 * @return the list of entities.
	 */
	const auto &get_entities() const { return _entities; };

	// TODO: maybe move this method to glob
	void add_entity(std::shared_ptr<Entity>);

	/**
	 * @return the list of views.
	 */
	const auto &get_views() const { return _views; };

	// TODO: maybe remove this method
	void add_view(std::shared_ptr<View> v) { _views->push_back(v); };

	void draw(sf::RenderWindow &w) override;

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
	std::shared_ptr<std::list<std::shared_ptr<Entity>>> _entities;
};

#endif
