#include <SFML/Graphics.hpp>

#include "button.hpp"
#include "glob.hpp"


Button::Button(const glob::vect &pos, const std::string &text) : Entity(pos) {
	_size = { 200, 50 };

	_text.setOrigin(glob::convert_vect(_size / 2));
	_text.setPosition(glob::convert_vect(pos));
	_text.setCharacterSize(100);
	_text.setFillColor(sf::Color::Red);
	_text.setString(text);

	_shape.setOrigin(glob::convert_vect(_size / 2));
	_shape.setPosition(glob::convert_vect(pos));
	_shape.setSize(glob::convert_vect(_size));
	_shape.setFillColor(sf::Color::White);
}


void Button::draw(sf::RenderWindow &w) {
	w.draw(_shape);
	w.draw(_text);
}
