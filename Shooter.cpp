#include "Shooter.hpp"

Shooter::Shooter(sf::Vector2f startPosition, sf::Vector2f tankSize, sf::Vector2f windowSize)
{
	texture.loadFromFile(".\\textures\\tank.png");
	tank.setTexture(&texture);
	tank.setSize(tankSize);
	tank.setOrigin({ tankSize.x / 2.f, tankSize.y / 2.f });
	tank.setPosition(startPosition);
}

sf::Vector2f Shooter::getPosition()
{
	return this->tank.getPosition();
}
sf::Vector2f Shooter::getSize()
{
	return this->tank.getSize();
}

void Shooter::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->tank, state);
}

float Shooter::getLeft()
{
	return tank.getPosition().x - tank.getSize().x / 2.f;
}
float Shooter::getRight()
{
	return tank.getPosition().x + tank.getSize().x / 2.f;
}
float Shooter::getUpper()
{
	return tank.getPosition().y - tank.getSize().y / 2.f;
}
float Shooter::getLower()
{
	return tank.getPosition().y + tank.getSize().y / 2.f;
}

void Shooter::update(sf::RenderWindow& window)
{
	time = clock.getElapsedTime();
	if (getLeft() > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		tank.move({-velocityValue, 0.0});
	}
	else if (getRight() < windowSize.x && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		tank.move({ velocityValue, 0.0 });
	}
	if (getUpper() > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		tank.move({ 0.0, -velocityValue });
	}
	else if (getLower() < windowSize.y && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		tank.move({ 0.0, velocityValue });
	}

	Bullet bullet({ 17,27 });
	bullet.setPosition({ getPosition().x, getPosition().y - tank.getSize().y / 2.f });

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && time.asMilliseconds() > pauseTime)
	{
		bullets.push_back(bullet);
		soundplay();
		clock.restart();
	}
	else if (time.asMilliseconds() < pauseTime)
	{
		//std::cout << "loading...\n";
	}
	else
	{
		//std::cout << std::endl;
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].update();
		window.draw(bullets[i]);
		if (bullets[i].getPosition().y < 0 || bullets[i].destroyed)
			bullets.erase(bullets.begin() + i);
	}
}

void Shooter::soundplay()
{
	buffer.loadFromFile(".\\sounds\\shot.wav");
	sound.setBuffer(buffer);
	sound.play();
}

void Shooter::setPosition(sf::Vector2f pos)
{
	tank.setPosition(pos);
}
