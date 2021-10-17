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
 _state = std::make_shared<StateMenu>();  
 _window = std::make_unique<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "Best game", sf::Style::Titlebar | sf::Style::Close);
isRunning = true; 

}

/*
    1) Handles close event, delegate other events to _state 
    2) calls _state update
    3) calls _state draw
*/
void GameController::update(){
    // clear screen 
    _window->clear(sf::Color::Black);
    std::shared_ptr<State> newState; 
    sf::Event event;
    // while there are pending events...
    while (_window->pollEvent(event)) { // while 
		switch (event.type) {
			case sf::Event::Closed:
				_window->close();
                isRunning = false; 
                return; // skip on current update() if closing window cuz we're done
			default: // delegate to State
                newState =  _state->handle_event(event); 
                if(newState != NULL){ 
                    std::cout << "right about to transition to new state" << std::endl; 
                    _state = newState; 
                    return; // maybe shouldn't directly return
                }
             
		}
	}
    std::cout << "stuff" << std::endl; 

    newState = _state->update();
    if(newState!=NULL){
        _state = newState; 
    } 
    _state->draw(*_window); 

    //display window
    _window->display(); 
}