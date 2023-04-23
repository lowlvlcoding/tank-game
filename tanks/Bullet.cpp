#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float moveSpeed)
{
	this->bulletShape.setTexture(*texture);

	this->bulletShape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = moveSpeed;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->bulletShape.getGlobalBounds();
}

void Bullet::update()
{
	//Movement
	this->bulletShape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->bulletShape);
}
