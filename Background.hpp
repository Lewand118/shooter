#pragma once
#include "SFML/Graphics.hpp"

class Background :public sf::Drawable
{
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	sf::Vector2f size;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape background;

public:
	Background(sf::Vector2f size);

};

