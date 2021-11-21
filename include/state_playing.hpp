#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP

#include "state.hpp"

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

class View;
class CeliaView;
class Entity;
class StateController;

/*
 * In-game state
 */
class StatePlaying : public State {
public:
	StatePlaying(std::shared_ptr<StateController>);

	/**
	 * @return the list of entities.
	 */
	const auto &get_entities() const { return _entities; };

	// TODO: maybe move this method implementation to glob
	void add_entity(std::shared_ptr<Entity>);

	/**
	 * @return the list of views.
	 */
	const auto &get_views() const { return _views; };

	// TODO: maybe remove this method
	void add_view(std::shared_ptr<View> v) { _views->push_back(v); };

	/**
	 * Draw entities to the screen
	 */
	void draw(sf::RenderWindow &) override;

	void handle_event(const sf::Event &) override;

	/*
	 * update each view and entity
	 */
	void update() override;

private:
	std::shared_ptr<std::list<std::shared_ptr<View>>> _views;
	std::shared_ptr<std::list<std::shared_ptr<Entity>>> _entities;
	std::shared_ptr<CeliaView> _celia_view;
};

#endif
