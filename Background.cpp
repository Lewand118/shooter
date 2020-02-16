#include "Background.hpp"

Background::Background(sf::Vector2f size)
{
	this->size = size;
	texture.loadFromFile(".\\textures\\background_white.jpg");
	sprite.setTexture(texture);
	//background.setTexture(&texture);
	//background.setPosition({0,0});
	//background.setSize(size);
	sprite.setPosition({0,0});
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
}
