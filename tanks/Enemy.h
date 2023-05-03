#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Enemy
{
private:
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
	int type, hp, hpMax, damage, points, textureX;
	float randomMove, speed;

	void initVariables();
	void initTexture();
	void initSprite();


public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;

	//Functions
	void rotateTank(int randDir);
	void update();
	void render(sf::RenderTarget* target);
};

