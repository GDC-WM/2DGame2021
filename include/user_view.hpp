#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP

#include <memory>
#include <SFML/Graphics.hpp>

#include "view.hpp"

class GameState;
class Actor;


class UserView : public View {
public:
	UserView(std::shared_ptr<GameState> game_state);

	/**
	 * @return whether the window is open
	 */
	const bool &running() const { return _running; };

	/**
	 * Draw the screen.
	 */
	void draw();

	void update() override;


private:
	std::unique_ptr<sf::RenderWindow> _window;
	std::shared_ptr<GameState> _game_state;
	bool _running = true;

	/**
	 * Respond to events
	 */
	void _listen(void);
};


#endif
