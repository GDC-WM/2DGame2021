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
	Button play_button { glob::vect(round(_state_controller->window().getSize().x) / 2, 200), "PLAY" };
	sf::Text _title_text;
	sf::Font font;
};


#endif
