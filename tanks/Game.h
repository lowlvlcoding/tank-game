#pragma once

#include <map>
#include "Player.h"
#include "Bullet.h"
/*
Game engine class
*/

class Game

{
private:
	//Window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//Player
	Player* playerClassPointer;//maybe rename this

	//Private functions
	void initializeWindow();
	void initTextures();

	void initializePlayer();


public:
	//Constructors, destructors
	Game();
	virtual ~Game();

	//Functions
	void run();


	void updatePollEvents();
	void updateInput();
	void updateBullets();
	void update();
	void render();

};

