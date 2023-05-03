#include "Enemy.h"

void Enemy::initVariables()
{
	this->type = 0;
	this->hpMax = 1;
	this->hp = 0;
	this->damage = 1;
	this->points = 100;
	this->textureX = 90;
	this->randomMove = 0;
	this->speed = 5.f;
	
}

void Enemy::initTexture()
{
	if (!this->enemyTexture.loadFromFile("Textures/enemy_animation.png"))
	{
		std::cout << "Error::Player::Inittexture::Texture not loaded" << std::endl;
	}
}

void Enemy::initSprite()
{
	//Set the texture to the sprite
	this->enemySprite.setTexture(this->enemyTexture);

	this->enemySprite.setTextureRect(sf::IntRect(270, 0, 90, 90)); //x,y,w,h
	this->enemySprite.scale(0.7f, 0.7f);
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->enemySprite.setPosition(pos_x, pos_y);

}

Enemy::~Enemy()
{
}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->enemySprite.getGlobalBounds();

}

//Functions
void Enemy::rotateTank(int randDir)
{
	this->enemySprite.setTextureRect(sf::IntRect(this->textureX * randDir, 0, 90, 90));
}

void Enemy::update()
{
	//this->enemySprite.move(0.f,this->speed);

	
	this->randomMove = rand() % 100 + 0;
	if (randomMove == 0)
	{
		this->enemySprite.move(0.f, -5.f);
		this->rotateTank(0);
	}
	else if (randomMove == 1|| randomMove == 5 || randomMove == 9)
	{
		this->enemySprite.move(5.f, 0.f);
		this->rotateTank(1);
	}
	else if (randomMove == 2 || randomMove == 6 || randomMove == 10)
	{
		this->enemySprite.move(-5.f, 0.f);
		this->rotateTank(2);
	}
	else if (randomMove == 3)
	{
		this->enemySprite.move(0.f, 5.f);
		this->rotateTank(3);
	}
	

}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->enemySprite);
}


