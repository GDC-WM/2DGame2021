#ifndef VIEW_HPP
#define VIEW_HPP

#include <list>
#include <memory>

class Entity;

/**
 * Controls an entity
 */
class View : public std::enable_shared_from_this<View> {
public:
	/**
	 * @param entities List of entities
	 */
	View(const std::shared_ptr<std::list<std::shared_ptr<Entity>>> &entities)
			: _entities(entities){};

	/**
	 * Update the view
	 */
	virtual void update() = 0;

protected:
	std::shared_ptr<std::list<std::shared_ptr<Entity>>> _entities;
};

#endif
