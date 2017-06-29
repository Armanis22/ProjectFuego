// ProjectFuego.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>

#include "Game.h"
#include "Random.h"
#include "GlobalConsts.h"
#include "Player.h"
#include "InputHolder.h"

bool fullscreen = false;
int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Project Fuego", sf::Style::Titlebar);
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
					window.create(fullscreen ? sf::VideoMode(FULLSCREENWIDTH, FULLSCREENHEIGHT) : sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Project Fuego", fullscreen ? sf::Style::Fullscreen : sf::Style::Titlebar);
				}

				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}

			InputManager::Instance().StoreKeyPressed(event);
			InputManager::Instance().GetKeysPressed();
			

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		game.Update(dt.asSeconds());
		game.Draw(&window);
		window.display();	
	}

	
	return 0;
}