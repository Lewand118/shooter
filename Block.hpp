#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Block :public sf::Drawable
{
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;

	sf::Texture texture;
	sf::RectangleShape block;
	float velocity = 1.f;
	
public:
	Block(sf::Vector2f blockSize);
	static int counter;
	bool destroyed = false;

	float getLeft();
	float getRight();
	float getUpper();
	float getLower();

	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	float getVelocity();
	void changeVelocity(float newVelocity);
	void setPosition(sf::Vector2f newPosition);
	void update();
};

