#include "Player.h"


void Player::initTexture()
{
	//Load a texture from a file
	if (!this->playerTexture.loadFromFile("Textures/tank.png"))
	{
		std::cout << "Error::Player::Inittexture::Texture not loaded" << std::endl;
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->playerSprite.setTexture(this->playerTexture);

	//Resize the sprite
	this->playerSprite.scale(0.15f, 0.15f);
}

//constructors and destructors
Player::Player()
{
	this->movementSpeed = 3.f;

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


void Player::move(const float dirX, const float dirY)
{
	this->playerSprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);

	//if (dirX != 0.f) this->playerSprite.rotate(this->movementSpeed * dirX);
	//else this->playerSprite.rotate(this->movementSpeed * dirY);

	
}

//Functions
void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);

}
