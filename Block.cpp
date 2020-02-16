#include "Block.hpp"

int Block::counter = 0;

Block::Block(sf::Vector2f blockSize)
{
	texture.loadFromFile(".\\textures\\bomb.png");
	block.setTexture(&texture);
	block.setSize(blockSize);
	block.setOrigin({ blockSize.x / 2.f, blockSize.y / 2.f });
	counter++;
}

void Block::setPosition(sf::Vector2f newPosition)
{
	block.setPosition(newPosition);
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->block, state);
}

void Block::update()
{
	block.move({ 0.0,velocity });
}

sf::Vector2f Block::getPosition()
{
	return block.getPosition();
}
sf::Vector2f Block::getSize()
{
	return block.getSize();
}

float Block::getLeft()
{
	return block.getPosition().x - block.getSize().x / 2.f;
}
float Block::getRight()
{
	return block.getPosition().x + block.getSize().x / 2.f;
}
float Block::getUpper()
{
	return block.getPosition().y - block.getSize().y / 2.f;
}
float Block::getLower()
{
	return block.getPosition().y + block.getSize().y / 2.f;
}

void Block::changeVelocity(float newVelocity)
{
	this->velocity = newVelocity;
}

float Block::getVelocity()
{
	return velocity;
}