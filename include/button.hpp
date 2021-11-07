#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "glob.hpp"


class Button : public Entity {
public:
	Button(const glob::vect &pos, const std::string &text);

	Button(const float &x, const float &y, const std::string &text)
		: Button({ x, y }, text) {};

	bool collides(const glob::vect &point) const override {
			return glob::collides_point_rect(point, _pos, _size); };

	void draw(sf::RenderWindow &) override;

	//TODO: add an enumerated type for button size


private:
	sf::Text _text;
	sf::RectangleShape _shape;
};


#endif
