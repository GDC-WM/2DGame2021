#ifndef CELIA_VIEW_HPP
#define CELIA_VIEW_HPP

#include "celia.hpp"
#include "view.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

/**
 * Controls Celia based on user's keyboard input and draws entities to the
 * screen
 */
class CeliaView : public View {
public:
	CeliaView(const std::shared_ptr<std::list<std::shared_ptr<Entity>>> &entities,
	          std::shared_ptr<Celia> character)
			: View(entities), _celia(character){};

	void update() override;

private:
	std::shared_ptr<Celia> _celia;
};

#endif
