#pragma once

#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
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

	//GUI
	sf::Font font;
	sf::Text pointText;

	//Player
	Player* playerClassPointer;//maybe rename this

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	int enemyCount;

	//Private functions
	void initializeWindow();
	void initTextures();
	void initGUI();
	void initializePlayer();
	void initializeEnemies();


public:
	//Constructors, destructors
	Game();
	virtual ~Game();

	//Functions
	void run();


	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateBullets();
	void updateEnemiesAndCombat();
	void update();
	void renderGUI();
	void render();

};

