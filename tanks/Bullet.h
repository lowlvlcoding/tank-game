#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Bullet
{
private:

	sf::Sprite bulletShape;

	sf::Vector2f direction;
	float movementSpeed;

public:
	Bullet();
	Bullet(sf::Texture* texture,float posX, float posY, float dirX, float dirY, float moveSpeed);
	virtual ~Bullet();

	//Accesor
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

