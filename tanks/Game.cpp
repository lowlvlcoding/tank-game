#include "Game.h"


//private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.width = 1280;
	this->videoMode.height = 720;

	this->window = new sf::RenderWindow(this->videoMode, "THE GAME!");
}

//constructors and destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();

}

Game::~Game()
{
	delete this->window;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
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

void Game::update()
{
	this->updatePollEvents();

}

void Game::render()
{
	/*
		Renders game objects
		clear old fram
		render objects
		display frame in window

	*/

	this->window->clear(sf::Color(255, 0, 0, 255));
	//Draw game objects
	this->window->display();

}