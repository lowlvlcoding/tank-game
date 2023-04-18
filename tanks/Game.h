#pragma once

#include <iostream>
#include <vector>
#include <ctime>

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

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;


	//private functions
	void initVariables();
	void initWindow();
	void initEnemies();


public:
	//Constructors, destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//functions
	void spawnEnemy();

	void updatePollEvents();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();



};

