#ifndef VIEW_HPP
#define VIEW_HPP

#include <list>
#include <memory>

class Actor;


class View : public std::enable_shared_from_this<View> {
public:
	View(const std::shared_ptr<std::list<std::shared_ptr<Actor>>> &actors) : _actors(actors) {};

	/**
	 * Update the view
	 */
	virtual void update() = 0;


protected:
	std::shared_ptr<std::list<std::shared_ptr<Actor>>> _actors;
};


#endif
