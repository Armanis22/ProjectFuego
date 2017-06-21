#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "ResourceHolder.h"


class Game;

namespace State
{
	class Game_State
	{

	public:
		Game_State(Game& game);
		~Game_State();

		virtual void Input() = 0;
		virtual void Update(float dt) = 0;
		// this arguement is temporary
		virtual void Draw(sf::RenderWindow* window) = 0;
	
	protected:
		Game* m_p_game;
		sf::Music music;




	};
}

