// ProjectFuego.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "Game.h"
#include "Random.h"

bool fullscreen = false;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 720), "Project Fuego", sf::Style::Titlebar);
	Game game;

	sf::Clock clock;
	Random::init();

	while (window.isOpen())								//--------------------- Start of game loop
	{
		sf::Time dt = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return &&
					event.key.alt)
				{
					window.close();
					fullscreen = !fullscreen;
					window.create(fullscreen ? sf::VideoMode(1920, 1080) : sf::VideoMode(1280, 720), "Project Fuego", fullscreen ? sf::Style::Fullscreen : sf::Style::Titlebar);
				}

				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		game.Draw(&window);
		game.Update(dt.asSeconds());
		window.display();	
	}

	
	return 0;
}