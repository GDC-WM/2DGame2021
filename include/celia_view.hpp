#ifndef CELIA_VIEW_HPP
#define CELIA_VIEW_HPP

#include "celia.hpp"
#include "view.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class CeliaView : public View {
public:
	CeliaView(const std::shared_ptr<std::list<std::shared_ptr<Entity>>> &entities,
	          std::shared_ptr<Celia> character)
			: View(entities), _celia(character){};

	/**
	 * Draw the screen
	 */
	void draw(sf::RenderWindow &);

	void update() override;

private:
	std::shared_ptr<Celia> _celia;
};

#endif
