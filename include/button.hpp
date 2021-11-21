#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "entity.hpp"
#include "glob.hpp"

#include <SFML/Graphics.hpp>
#include <string>

/**
 * Entity meant to be used as a clickable button via the collides method
 */
class Button : public Entity {
public:
	/**
	 * @param pos Vector center point of the button
	 * @param text Text to display on the button
	 */
	Button(const glob::vect &pos, const std::string &text);

	/**
	 * @param x X value of the center point of the button
	 * @param y Y value of the center point of the button
	 * @param text Text to display on the button
	 */
	Button(const float &x, const float &y, const std::string &text) : Button({x, y}, text){};

	/**
	 * Detect a collision
	 *
	 * @param point Vector position to test (usually supply the mouse position)
	 * @return True if the point falls within this entity
	 */
	bool collides(const glob::vect &point) const override {
		return glob::collides_point_rect(point, _pos, _size);
	};

	/**
	 * Draw itself on the RenderWindow
	 *
	 * @param RenderWindow RenderWindow to draw to
	 */
	void draw(sf::RenderWindow &) override;

	// TODO: add an enumerated type for button size?

private:
	sf::Text _text;
	sf::Font _font;
	sf::RectangleShape _shape;
};

#endif
