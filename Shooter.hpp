#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "Bullet.hpp"
class Shooter :public sf::Drawable
{
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;

	sf::Texture texture;
	sf::RectangleShape tank;
	float velocityValue = 9.f;
	sf::Vector2f velicity{ velocityValue, velocityValue };
	sf::Vector2f windowSize{ 1000, 800 };
	sf::Vector2f bulleStartPos;
	sf::Vector2f bulletSize{ 17, 27 };
	int pauseTime = 500;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	//friend class Window;
public:
	Shooter(sf::Vector2f startPosition, sf::Vector2f tankSize, sf::Vector2f windowSize);
	bool destroyed = false;

	sf::Clock clock;
	sf::Time time;
	
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void setPosition(sf::Vector2f);

	std::vector<Bullet> bullets;

	void soundplay();

	float getLeft();
	float getRight();
	float getUpper();
	float getLower();
	void update(sf::RenderWindow& window);

};

