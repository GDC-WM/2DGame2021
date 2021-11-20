#ifndef AI_VIEW_HPP
#define AI_VIEw_HPP

#include "glob.hpp"

//#include <SFML/Graphics.hpp>
#include <memory>

class Entity;
class Character;


class AiView : public View{
public: 
	/**
	 * @brief Construct a new AIView object
	 * 
	 * @param actor the ai
	 */
	AIView(const std::shared_ptr<Entity> actor);

	/**
	 * @brief check to see if target entity is in range
	 * 
	 * @param target the current target of the ai
	 * 
	 * @return true if the target is in range of the ai entity
	 * @return false if the target is out of range
	 */
	virtual bool in_range(std::shared_ptr<Character> target);

	/**
	 * @brief give the ai a new target
	 * 
	 * @param allegiance Allegiance of the AI (good, bad, neutral)
	 * 
	 * @return true if a new target was found
	 * @return false if no new targets exist
	 */
	bool update_target(const glob::Allegiance allegiance);

	virtual void update(void){};

protected:
	int range;
	std::shared_ptr<Entity> actor;
	std::shared_ptr<Character> target;
}