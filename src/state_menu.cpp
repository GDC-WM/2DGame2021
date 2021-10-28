#include <iostream>
#include <SFML/Graphics.hpp>

#include "state_controller.hpp"
#include "state_menu.hpp"
#include "state_playing.hpp"

// MAKE SURE TO ADD PNGs TO DEBUG FOLDER BEFORE RUNNING!!!!


StateMenu::StateMenu(std::shared_ptr<StateController> sc) : State(sc) {
	
	// (DONT ERASE!) This is example code being used for the rest of the menu design
	////////////////////////////////////////////////////////////////////////////////////////////
	/*
	
	text.setString("Start playing big noob!");
	text.setCharacterSize(100);
	text.setPosition(sf::Vector2f(200, 200));
	text.setFillColor(sf::Color::Red);

	if (!font.loadFromFile("../fonts/arial.ttf"))
		std::cout << "can't load font" << std::endl;
	else text.setFont(font);
	
	*/
	////////////////////////////////////////////////////////////////////////////////////////////
	

}


void StateMenu::draw(sf::RenderWindow &window) const {
	// (DONT ERASE!) This is example code being used for the rest of the menu design
	////////////////////////////////////////////////////////////////////////////////////////////
	/*
	
	// window.draw button
	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(100, 100));

	window.draw(circle);
	
	// window.draw(text);
	
	*/
	

	// Menu Background 
	sf::Texture menu_bkg_texture;
	if (!menu_bkg_texture.loadFromFile("../resources/menu_temp_background2.png"))
	{
		std::cout << "can't load background sprite" << std::endl;
	}
	sf::Sprite menu_bkg;
	menu_bkg.setTexture(menu_bkg_texture);
	menu_bkg.setPosition(sf::Vector2f(0, 0));
	window.draw(menu_bkg);

	// New Game Button
	sf::Texture new_game_button_texture;
	if (!new_game_button_texture.loadFromFile("../resources/btn_newGame.png"))
	{
		std::cout << "can't load button sprite" << std::endl;
	}
	sf::Sprite new_game_button;
	new_game_button.setTexture(new_game_button_texture);
	new_game_button.setPosition(sf::Vector2f(540, 300));
	window.draw(new_game_button);

	// Load Game Button
	sf::Texture load_game_button_texture;
	if (!load_game_button_texture.loadFromFile("../resources/btn_LoadGame.png"))
	{
		std::cout << "can't load button sprite" << std::endl;
	}
	sf::Sprite load_game_button;
	load_game_button.setTexture(load_game_button_texture);
	load_game_button.setPosition(sf::Vector2f(540, 400));
	window.draw(load_game_button);

}


void StateMenu::handle_event(const sf::Event &e) {
	int mouse_x = sf::Mouse::getPosition(_state_controller->window()).x;
	int mouse_y = sf::Mouse::getPosition(_state_controller->window()).y;
	
	switch (e.type) {
		// play button switches state playing
		case sf::Event::MouseButtonPressed:
			// TODO: temporary crap, later use a button actor check collision
			// with the mouse pointer:
			if (540 < mouse_x < 799)
				_state_controller->states().push(
						std::make_shared<StatePlaying>(_state_controller));
			break;
		default:;
	}
}
