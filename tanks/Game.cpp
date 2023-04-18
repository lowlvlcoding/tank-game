#include "Game.h"


//private functions
void Game::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
}

void Game::initWindow()
{
	this->videoMode.width = 1280;
	this->videoMode.height = 720;

	this->window = new sf::RenderWindow(this->videoMode, "THE GAME!");

	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(sf::Vector2f(40.f,60.f));
	//this->enemy.setScale(sf::Vector2f(0.5f, 0.5f)); //makes the size of the object smaller or bigger, can also change size in setsize();
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);


}

//constructors and destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();

}

Game::~Game()
{
	delete this->window;
}

//Accesors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

//Functions
void Game::spawnEnemy()
{
	/*spawns enemies and sets positions and adds enemy to the vector*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);

	//spawn the enemy
	this->enemies.push_back(this->enemy);

}

void Game::updatePollEvents()
{
	while (this->window->pollEvent(this->ev)) {

		switch (this->ev.type) {

		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}


	}

}

void Game::updateEnemies()
{
	/*
	Spawns enemies while the total amount of enemies is smaller than max
	*/

	//Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies) {
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			//Spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}

	//Move enemies

	//for (auto& e : this->enemies) 
	//{
	//	e.move(0.f, 5.f);
	//}

}

void Game::update()
{
	this->updatePollEvents();
	this->updateEnemies();
}

void Game::renderEnemies()
{
	//Rendering the enemies
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}


}

void Game::render()
{
	/*
		Renders game objects
		clear old fram
		render objects
		display frame in window

	*/

	this->window->clear();

	//Draw game objects
	this->renderEnemies();
	this->window->display();

}