#include "Game.h"

//Private functions
void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280,720),"Tanks", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
	
}

void Game::initializePlayer()
{		

	this->playerClassPointer = new Player();
}

//constructors and destructors
Game::Game()
{
	this->initializeWindow();
	this->initTextures();
	this->initializePlayer();

}

Game::~Game()
{
	delete this->window;
	delete this->playerClassPointer;

	//Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	//Delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}
}

//Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed) this->window->close();
		//if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape) this->window->close();
	}

}

void Game::updateInput()
{
	//Move player and rotate
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->playerClassPointer->move(-1.f, 0.f);
		//this->playerClassPointer->rotate;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))this->playerClassPointer->move(1.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))this->playerClassPointer->move(0.f, -1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))this->playerClassPointer->move(0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"],this->playerClassPointer->getPos().x, this->playerClassPointer->getPos().y, 0.f, 0.f, 0.f));
	}
}

void Game::updateBullets()
{
	for (auto* bullet : this->bullets)
	{
		bullet->update();
	}
}

void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->updateBullets();
}

void Game::render()
{
	this->window->clear();

	//Draw all the stuff
	this->playerClassPointer->render(*this->window);

	for (auto* bullet : this->bullets) 
	{
		bullet->render(this->window);
	}


	this->window->display();
}

