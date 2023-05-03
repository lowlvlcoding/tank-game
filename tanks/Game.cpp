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

void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("Fonts/RobotoMono-Regular.ttf"))
	{
		std::cout << "Error failed to load font" << std::endl;
	}

	//Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(30);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("test");


}

void Game::initializePlayer()
{		

	this->playerClassPointer = new Player();
}

void Game::initializeEnemies()
{
	//this->enemy = new Enemy(rand() % 1190 + 1, rand() % 630 + 10);
	this->spawnTimerMax = 20.f;
	this->spawnTimer = this->spawnTimerMax;
	this->enemyCount = 0;
}

//constructors and destructors
Game::Game()
{
	this->initializeWindow();
	this->initTextures();
	this->initGUI();
	this->initializePlayer();
	this->initializeEnemies();

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

	//Delete enemies
	for (auto* i : this->enemies)
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
		this->playerClassPointer->rotateTank(2);
		this->playerClassPointer->move(-1.f, 0.f);
		//this->playerClassPointer->rotate;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->playerClassPointer->rotateTank(1);
		this->playerClassPointer->move(1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->playerClassPointer->rotateTank(0);
		this->playerClassPointer->move(0.f, -1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->playerClassPointer->rotateTank(3);
		this->playerClassPointer->move(0.f, 1.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& this->playerClassPointer->canAttack())
	{
		this->bullets.push_back(
		new Bullet(
		this->textures["BULLET"],
		this->playerClassPointer->getPos().x + this->playerClassPointer->getBounds().width/2.f, 
		this->playerClassPointer->getPos().y, 
		0.f, 
		-1.f, 
		5.f)
		);
	}
}

void Game::updateGUI()
{
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//Bullet is removed if outside of the screen
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updateEnemiesAndCombat()
{
	//Added enemy counter to limit amount on screen, will remove later
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax
		&& enemyCount!=5)
	{
		this->enemies.push_back(new Enemy(rand() % 1190 + 1, rand() % 150 + 10));
		this->spawnTimer = 0.f;
		this->enemyCount++;
	}



	for (int i =0; i < this->enemies.size(); ++i)
	{
		this->enemies[i]->update();

		for (size_t j = 0; j < this->bullets.size(); j++)
		{
			if (this->bullets[j]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->bullets.erase(this->bullets.begin() + j);
				this->enemies.erase(this->enemies.begin() + i);
			}
		}


	}

}

void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->playerClassPointer->update();
	this->updateBullets();
	this->updateEnemiesAndCombat();
	this->updateGUI();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
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

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	this->renderGUI();

	this->window->display();
}

