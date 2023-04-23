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

	//Private functions
	void initTexture();
	void initSprite();


public:
	Player();
	virtual ~Player();

	//Accessor
	const sf::Vector2f& getPos() const;

	//Functions
	void move(const float dirX, const float dirY);

	void update();
	void render(sf::RenderTarget& target);


};

