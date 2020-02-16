#include "Window.hpp"

Window::Window(sf::Vector2f windowSize)
	:window(sf::VideoMode((unsigned int)windowSize.x, (unsigned int)windowSize.y), "Shooter", sf::Style::Default)
{
	this->windowSize = windowSize;
}

void Window::run()
{
	srand(time(NULL));
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Shooter tank({ (windowSize.x - tankSize.x / 2.f) / 2, windowSize.y - tankSize.y / 2.f }, {68, 86}, windowSize);
	Block bomb({ bombSize.x,bombSize.y });

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		window.draw(background);

		if (gameRun)
		{
			timeElapsed = timer.getElapsedTime();
			sf::Event e;
			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
			}

			if (timeElapsed.asMilliseconds() > bombPause)
			{
				levelUp();
				bomb.setPosition({ (rand() % ((int)windowSize.x - (int)tankSize.x)) + tankSize.x / 2, 0.0 });
				bombs.push_back(bomb);
				timer.restart();
			}

			for (size_t i = 0; i < bombs.size(); i++)
			{
				bombs[i].update();
				window.draw(bombs[i]);
				if (bombs[i].getLower() > windowSize.y || bombs[i].destroyed)
					bombs.erase(bombs.begin() + i);
			}

			bulletCollision(bombs, tank);
			tankCollision(bombs, tank);
			printScore(score);

			if (tank.destroyed)
				gameRun = false;

			tank.update(window);
			window.draw(tank);
		}
		else
		{
			gameOver(bombs, tank);
			sf::Event e;
			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					playAgain(bombs, tank);
			}
		}

		window.display();
	}
}

void Window::bulletCollision(std::vector<Block>& bombs, Shooter& tank)
{
	for (auto& i : bombs)
		for (size_t j = 0; j < tank.bullets.size(); j++)
			if (i.getLower() > tank.bullets[j].getUpper() && i.getUpper() < tank.bullets[j].getLower() && i.getLeft() < tank.bullets[j].getRight() && i.getRight() > tank.bullets[j].getLeft())
			{
				i.destroyed = true;
				tank.bullets[j].destroyed = true;
				score++;
			}		
}

void Window::tankCollision(std::vector<Block>& bombs, Shooter& tank)
{
	for (auto& i : bombs)
		if (i.getLower() >= windowSize.y || (i.getLower() > tank.getUpper() && i.getUpper() < tank.getLower() && i.getLeft() < tank.getRight() && i.getRight() > tank.getLeft()))
			tank.destroyed = true;	
}

void Window::levelUp()
{
	if (score % 50 >= 49)
	{
		float vel;
		for (auto& i : bombs)
		{
			vel = i.getVelocity();
			vel *= 2;
			i.changeVelocity(vel);
		}
		bombPause -= 150;
	}
}

void Window::gameOver(std::vector<Block>& bombs, Shooter tank)
{
	std::string finalString = "Game Over\nYour score: " + std::to_string(score) + "\nThe best in this session: " + std::to_string(bestScore) + "\n\nPress Enter to play again...\n";
	text.setString(finalString);
	text.setPosition({ 0,0 });
	text.setCharacterSize(60);
	text.setFillColor(sf::Color::Blue);

	window.draw(text);
}

void Window::playAgain(std::vector<Block>& bombs, Shooter& tank)
{
	tank.destroyed = false;
	gameRun = true;
	for (size_t i = 0; i < bombs.size(); i++)
		bombs.erase(bombs.begin());
	tank.setPosition({ (windowSize.x - tankSize.x / 2.f) / 2, windowSize.y - tankSize.y / 2.f });
	score = 0;
}

void Window::printScore(int num)
{
	if (score > bestScore)
		bestScore = score;

	font.loadFromFile("arial_narrow_7.ttf");
	text.setFont(font);
	std::string finalString = "Score: " + std::to_string(score) + "\nBest score: " + std::to_string(bestScore);
	text.setString(finalString);
	text.setPosition({ 0,0 });
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::Blue);

	window.draw(text);
}