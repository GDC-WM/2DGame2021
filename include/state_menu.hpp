#ifndef STATE_MENU_HPP
#define STATE_MENU_HPP

#include <memory>
#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "state_controller.hpp"
#include "button.hpp"


class StateMenu : public State {
public:
	StateMenu(std::shared_ptr<StateController>);

	void draw(sf::RenderWindow &) override;

	void handle_event(const sf::Event &) override;

	void update() override {};


public:
	Button play_button { glob::vect(200, 200), "PLAY" };
	sf::Text text;
	sf::Font font;
};


#endif
