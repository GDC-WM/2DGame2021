#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP

#include <memory>
#include <SFML/Graphics.hpp>

#include "view.hpp"
#include "main_character.hpp"


class UserView : public View {
public:
	UserView(const std::shared_ptr<std::list<std::shared_ptr<Entity>>> &entities,
			std::shared_ptr<MainCharacter> character)
			: View(entities), _character(character) {};

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

	void update() override {};


private:
	std::shared_ptr<MainCharacter> _character;
};


#endif
