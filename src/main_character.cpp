#include "main_character.hpp"
#include "glob.hpp"
#include <iostream>

MainCharacter::MainCharacter(/* args */)
{
    mainShape.setRadius(50); 
    mainShape.setFillColor(sf::Color::Red); 
    _pos = glob::vect(100, 0); 
    mainShape.setPosition(glob::convert_vect(_pos));
    _velocity = glob::vect(900, -900); 
}

MainCharacter::~MainCharacter()
{
}

void MainCharacter::draw(sf::RenderWindow &window){
   // std::cout << "MAIN CHARACTER IS DRAWING LETS GO" << std::endl; 
    window.draw(mainShape); 
}

void MainCharacter::update(){
    _pos += _velocity * glob::dt; // samething as default actor, making it explicit for now
    mainShape.setPosition( glob::convert_vect(_pos) );
    //std::cout << _pos.x << _pos.y << std::endl; 
    std::cout << mainShape.getPosition().x << mainShape.getPosition().y << std::endl; 
    
}