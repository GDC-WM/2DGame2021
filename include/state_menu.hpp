#include "state.hpp"


class StateMenu : public State {
public:
	StateMenu(std::shared_ptr<StateController>);

	void draw(sf::RenderWindow &) const override;

	void handle_event(const sf::Event &) override;

	void update() override {};


public:
	sf::Text text;
	sf::Font font;
};
