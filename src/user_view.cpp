#include <memory>
#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "entity.hpp"


void UserView::draw(sf::RenderWindow &w) {
	// draw entities
	for (auto entity : *_entities) entity->draw(w);
}

/*
* UserView is quite a special boi! It is not like the other views, since 
* StatePlaying.handle_event is delegated to this view. 
*/
void UserView::handle_event(const sf::Event &e) {
	switch (e.type) {
		// TODO: do stuff here
		//case sf::Keyboard::W:
		default:; // ignore other events
	}
}
