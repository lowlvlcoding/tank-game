#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{

private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	float movementSpeed;
	float attackCooldown;
	float attackCooldownMax;
	int textureX;

	//Private functions
	void initVariables();
	void initTexture();
	void initSprite();


public:
	Player();
	virtual ~Player();

	//Accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	//Functions
	void rotateTank(int dirTemp);
	void move(const float dirX, const float dirY);
	const bool canAttack();

	void updateAttackCooldown();
	void update();
	void render(sf::RenderTarget& target);


};

