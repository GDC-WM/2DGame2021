#include "state.hpp"

class GameController{
    public: 
        GameController(); 

    public: 
        void update(); 

    public: 
        bool isRunning; // fuck private vars baby

    private: 
        std::shared_ptr<State> _state; 
        std::unique_ptr<sf::RenderWindow> _window; 
        
};