#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
/*
Game engine class
*/


class Game

{
private:

	//private variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//private functions
	void initVariables();
	void initWindow();


public:
	//Constructors, destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//functions
	void updatePollEvents();
	void update();
	void render();



};

