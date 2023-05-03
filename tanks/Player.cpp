#include "Player.h"


void Player::initVariables()
{
	this->movementSpeed = 3.f;
	this->attackCooldownMax = 30.f;
	this->attackCooldown = this->attackCooldownMax;
	this->textureX=90;
}

void Player::initTexture()
{
	//Load a texture from a file
	//if (!this->playerTexture.loadFromFile("Textures/tank.png"))
	if (!this->playerTexture.loadFromFile("Textures/tank_animation.png"))
	{
		std::cout << "Error::Player::Inittexture::Texture not loaded" << std::endl;
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->playerSprite.setTexture(this->playerTexture);


	this->playerSprite.setTextureRect(sf::IntRect(0,0,90,90)); //x,y,w,h
	this->playerSprite.setPosition(500.f,630.f);
	//Resize the sprite
	this->playerSprite.scale(0.7f, 0.7f);
}

//constructors and destructors
Player::Player()
{
	
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

const sf::Vector2f& Player::getPos() const
{
	return this->playerSprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->playerSprite.getGlobalBounds();
}


void Player::rotateTank(int dirTemp)
{
	this->playerSprite.setTextureRect(sf::IntRect(this->textureX*dirTemp, 0, 90, 90));
}

void Player::move(const float dirX, const float dirY)
{
	this->playerSprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);

	//if (dirX != 0.f) this->playerSprite.rotate(10.f);
	//else this->playerSprite.rotate(-10.f);

	
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttackCooldown()
{
	if(this->attackCooldown < this->attackCooldownMax) this->attackCooldown += 0.5f;
}

//Functions
void Player::update()
{
	this->updateAttackCooldown();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);

}
