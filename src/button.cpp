#include <SFML/Graphics.hpp>
#include <iostream>

#include "button.hpp"
#include "glob.hpp"


Button::Button(const glob::vect &pos, const std::string &text) : Entity(pos) {
	_size = { 300, 100 };

	_text.setString(text);
	_text.setOrigin(120,60);
	_text.setPosition(glob::convert_vect(pos));
	_text.setCharacterSize(100);
	_text.setFillColor(sf::Color::Red);
	if (!_font.loadFromFile("../fonts/arial.ttf"))
		std::cout << "can't load font" << std::endl;
	else _text.setFont(_font);

	_shape.setOrigin(glob::convert_vect(_size / 2));
	_shape.setPosition(glob::convert_vect(pos));
	_shape.setSize(glob::convert_vect(_size));
	_shape.setFillColor(sf::Color::White);
}


void Button::draw(sf::RenderWindow &w) {
	w.draw(_shape);
	w.draw(_text);
}
