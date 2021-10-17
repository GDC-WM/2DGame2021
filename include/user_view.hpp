#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP

#include <memory>
#include <SFML/Graphics.hpp>

#include "view.hpp"

class GameState;
class Actor;


class UserView : public View {
public:
	UserView(std::shared_ptr<GameState>);

	/**
	 * Draw the screen
	 */
	void draw(sf::RenderWindow &w);

	/**
	 * Respond to event
	 */
	void handle_event(const sf::Event &e);

	void update() override;


private:
	std::shared_ptr<GameState> _game_state;
};


#endif
