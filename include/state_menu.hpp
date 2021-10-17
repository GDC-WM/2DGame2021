
#include "state.hpp"

class StateMenu: public State{
    public: 
        StateMenu(){}; 

        void draw(sf::RenderWindow &w) const override; 

        std::shared_ptr<State> handle_event(const sf::Event &) override; 

        std::shared_ptr<State> update() override; 

};