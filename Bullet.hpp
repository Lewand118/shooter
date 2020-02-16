#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Bullet :public sf::Drawable
{
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;

	sf::Texture texture;
	sf::RectangleShape bullet;
	float velocityValue = 19.f;
	sf::Vector2f velocity{ 0.0, -velocityValue };
public:
	Bullet(sf::Vector2f bulletSize); // sf::Vector2f startPosition, sf::Vector2f bulletSize
	static int counter;
	bool destroyed = false;

	float getLeft();
	float getRight();
	float getUpper();
	float getLower();
	
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void setPosition(sf::Vector2f newPosition);
	
	void update();
};

