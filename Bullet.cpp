#include "Bullet.hpp"

int Bullet::counter = 0;

Bullet::Bullet(sf::Vector2f bulletSize) // sf::Vector2f startPosition, sf::Vector2f bulletSize
{
	texture.loadFromFile(".\\textures\\bullet.png");
	bullet.setTexture(&texture);
	bullet.setSize(bulletSize);
	bullet.setOrigin({ bulletSize.x / 2.f, bulletSize.y / 2.f });
	//bullet.setPosition(startPosition);
	counter++;
}

void Bullet::setPosition(sf::Vector2f newPosition)
{
	bullet.setPosition(newPosition);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->bullet, state);
}

void Bullet::update()
{
	bullet.move({ 0.0, -velocityValue });
}

sf::Vector2f Bullet::getPosition()
{
	return bullet.getPosition();
}
sf::Vector2f Bullet::getSize()
{
	return bullet.getSize();
}

float Bullet::getLeft()
{
	return bullet.getPosition().x - bullet.getSize().y / 2.f;
}
float Bullet::getRight()
{
	return bullet.getPosition().x + bullet.getSize().x / 2.f;
}
float Bullet ::getUpper()
{
	return bullet.getPosition().y - bullet.getSize().y / 2.f;
}
float Bullet::getLower()
{
	return bullet.getPosition().y + bullet.getSize().y / 2.f;
}