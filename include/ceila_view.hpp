#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP

#include "ceila.hpp"
#include "view.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class CeilaView : public View {
public:
	CeilaView(const std::shared_ptr<std::list<std::shared_ptr<Entity>>> &entities,
	          std::shared_ptr<Ceila> character)
			: View(entities), _ceila(character){};

	/**
	 * Draw the screen
	 */
	void draw(sf::RenderWindow &);

	/**
	 * Respond to event
	 *
	 * UserView is special. StatePlaying.handle_event is delegated to this view.
	 */
	void handle_event(const sf::Event &);

	void update() override{};

private:
	std::shared_ptr<Ceila> _ceila;
};

#endif