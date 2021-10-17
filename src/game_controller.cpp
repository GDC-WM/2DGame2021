/*fields: 
    state: StatePlaying | StateMenu | StatePause   
methods: 
    update // called by main loop 
        1) polls event and calls state.handleEvent(event) with the event 
            state.handleEvent
        2) calls state.update(), state.enter(), once we sense state.update() returns 
        a different state, we can set state to new state and 
        call state.enter() in the game controller  
        3) calls state.draw  */

#include "game_controller.hpp"
#include "state_menu.hpp"
#include <iostream>
GameController::GameController(){
 // instantiate to title
 _state = new StateMenu(); 
 _window = std::make_unique<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "Best game", sf::Style::Titlebar | sf::Style::Close);
isRunning = true; 

    sf::CircleShape circle(50); 
    circle.setFillColor(sf::Color::Red); 
    _window->draw(circle);
}


void GameController::update(){
    sf::Event event;
    // while there are pending events...
    while (_window->pollEvent(event)) { // while 
		switch (event.type) {
			case sf::Event::Closed:
				_window->close();
                isRunning = false; 
                return; // skip on current update() if closing window cuz we're done
			default: // delegate to State
                _state->handle_event(event); 
             
		}
	}

    std::shared_ptr<State> NewState = _state->update();
    if(NewState!=NULL){
        //_state = &NewState; 
    } 
    _state->draw(*_window); 
}