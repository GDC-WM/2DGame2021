From what I understand:

Originally, from Game Design class with Professor Peers, we had the following components:

- *Game Application Layer*
- *View*
- *Logic*

![Application Layer](docs/application_layer.png)

![Logic](docs/logic.png)

![View](docs/view.png)

![Diagram](docs/diagram.png)

And then anything to handle them could be added.

But the more *conventional* version of this structure is called:

- *Model*
- *View*
- *Controller*


![MVC](docs/mvc.png)



Which is basically the same aside from a few differences:

- *Game Application Layer* = while loop that keeps the game going
- *Model* = manipulates any data, art, music, fonts, anything used for the game

- *View* = what something can see, hear, and manipulate in the world (music, inputting keys, drawing anything like sprites, drawables) the USER INTERFACE/Front End  

- *Controller -* reacts to the view (any input or stuff happening to ingame objects) and handles back end stuff like position, velocity, direction, etc.
- *Logic* = controls Back end stuff 


`	`Usually, you want to make a class hierarchy, or source files you can abstract or make special conditions on. Like with the entity class, you can make it have a certain size, position, and speed. Then with the missile and main character class, you can specify how it’ll move with that speed.

![Class Hierarchy](docs/class_hierarchy.png)

Sort of counter-intuitive, you would think something that goes into use of another class would point to that class. But in class hierarchy diagrams, you have arrows pointing to what the class is using. Button is using entity and main character is using character. All states use the State class. Ones without arrows are just tools we currently use. glob::vect is a class that frees us from SFML’s vectors, while providing more functionality (lots of useful methods and operator overloading). 








*Class by class summary:*

*Main* - it’s the game loop! Loops with a while loop and has a thread sleeper for frames

*Glob.hpp* - makes a vector struct and vector operations and collision using vectors

(So we don’t have to load SFML in every file)

*Entity* - is something with size, position, velocity

*Button* - draws text and a rectangle (hopefully a sprite or custom text soon)

*Character* - can move left or right with Entity’s speed

*Celia* - logic for Ceila, currently only has the cannon spritesheet and animation

*View* - a general purpose view class that contains a shared pointered list of entities to be pulled and drawn by a State

*CeliaView* - uses the Ceila logic

*Missile* - another entity that has its own way of moving and turning with acceleration

*MissileAI* - should target something and turn to match its position

*State* - base state class that draws something; allows for customization on top like a main menu or playing state

Allows for handling events like key presses or changes in the window like aspect ratio

*State Controller* - is the logic of all states and keeps a *stack* of states to keep track what is currently doing what

- **Each state is a “view”, State Controller is a “logic” that each state uses to keep track.**

*State Playing* - Adds all entities/things including character view(s) to a view vector and draws the entities

*State Main Menu* - allows you to add text, titles, sprites, anything really and draw any entities

You can currently draw art to States Playing and Main Menu.
