#include <memory>
#include <SFML/Graphics.hpp>

#include "user_view.hpp"
#include "actor.hpp"


void UserView::draw(sf::RenderWindow &w) {
	// draw actors
	for (auto actor : *_actors) actor->draw(w);
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
