#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Shooter.hpp"
#include "Block.hpp"
#include "Background.hpp"

class Window
{
	sf::Vector2f tankSize{ 64,86 };
	sf::Vector2f bombSize{ 21,30 };
	Background background{windowSize};

	sf::RenderWindow window;
	sf::Vector2f windowSize;
	std::vector<Block> bombs;

	sf::Text text;
	sf::Font font;

	sf::Clock timer;
	sf::Time timeElapsed;
	int bombPause = 1500;
	bool gameRun = true;

	int score = 0;
	int bestScore = 0;

	void bulletCollision(std::vector<Block>& bombs, Shooter& tank);
	void tankCollision(std::vector<Block>& bombs, Shooter& tank);
	void levelUp();
	void gameOver(std::vector<Block>& bombs, Shooter tank);
	void playAgain(std::vector<Block>& bombs, Shooter& tank);
	void printScore(int num);

public:
	Window(sf::Vector2f windowSize);

	
	

	void run();
};

