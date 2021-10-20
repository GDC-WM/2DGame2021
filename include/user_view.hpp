#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP

#include <memory>
#include <SFML/Graphics.hpp>

#include "view.hpp"


class UserView : public View {
public:
	UserView(const std::shared_ptr<std::list<std::shared_ptr<Actor>>> &actors)
			: View(actors) {};

	/**
	 * Draw the screen
	 */
	void draw(sf::RenderWindow &w);

	/**
	 * Respond to event
	 */
	void handle_event(const sf::Event &e);

	void update() override {};
};


#endif
