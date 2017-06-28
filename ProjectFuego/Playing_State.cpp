#include "stdafx.h"
#include "Playing_State.h"

namespace State
{
	Playing_State::Playing_State(Game & game) :
		Game_State(game)
	{
		// testing resource stuff. temp
		music.openFromFile("Assets/Music/old_city_theme.ogg");
		music.setVolume(100);
		//music.play();
		music.setLoop(true);
		
	}
	

	void Playing_State::Input()
	{

	}

	void Playing_State::Update(float dt)
	{

	}

	void Playing_State::Draw(sf::RenderWindow* window)
	{
		
	}
}
