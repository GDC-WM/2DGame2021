#ifndef AI_VIEW_HPP
#define AI_VIEw_HPP

#include "glob.hpp"
#include "view.hpp"
#include "entity.hpp"
#include "character.hpp"

#include <SFML/Graphics.hpp>
#include <memory>




class AiView : public View{
public: 
	/**
	 * @brief Construct a new AIView object
	 * 
	 * @param actor the ai
	 * @param entities list of all entities in the game
	 */
	AIView(const std::shared_ptr<std::list<std::shared_ptr<Entity>>> &entities,
	          std::shared_ptr<Entity> actor) : View(entities) _actor(actor){};

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
	std::shared_ptr<Entity> _actor;
	std::shared_ptr<Character> target;
	std::shared_ptr<std::list<std::shared_ptr<Entity>>> &entities
}