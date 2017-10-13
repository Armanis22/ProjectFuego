// ProjectFuego.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "lua.hpp"

#include "Game.h"
#include "Random.h"
#include "GlobalConsts.h"
#include "Player.h"
#include "InputHolder.h"

//extern "C"
//{
//#include <lua.h>
//#include <lualib.h>
//}


bool fullscreen = false;
int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Project Fuego", sf::Style::Titlebar);
	Game game;


	sf::Clock clock;
	Random::init();


	//lua test shit
		lua_State* L = luaL_newstate();
		luaL_openlibs(L);

		if (luaL_dofile(L, "Scripts/test.lua"))
		{
			const char* err = lua_tostring(L, -1);
			printf(err);
		}

		luaL_openlibs(L);

	//end of tut lua
	//start of game ai book lua
		/*lua_State* pL = luaL_newstate();
		luaopen_base(pL);
		luaopen_string(pL);
		luaopen_table(pL);
		luaopen_math(pL);
		luaopen_io(pL);
		if (int error = luaL_dofile(pL, "Scripts/new_test.lua") != 0)
		{
			printf("\n[C++] ERROR%d: problem with lua script file \n\n", error);
		}


		lua_close(pL);*/

	// end of lua testing

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

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		game.Update(dt.asSeconds());
		game.Draw(&window);
		window.display();	
	}
	lua_close(L);

	return 0;
}