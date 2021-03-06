#ifndef STATE_MENU_HPP
#define STATE_MENU_HPP

#include "button.hpp"
#include "state.hpp"
#include "state_controller.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

/**
 * Main menu state
 */
class StateMenu : public State {
public:
	StateMenu(std::shared_ptr<StateController>);

	void draw(sf::RenderWindow &) override;

	void handle_event(const sf::Event &) override;

	void update() override{};

public:
	Button play_button{glob::vect(round(_state_controller->window().getSize().x) / 2, 200), "PLAY"};
	sf::Text _title_text;
	sf::Font _font;
};

#endif
