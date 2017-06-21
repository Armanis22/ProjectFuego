#include "stdafx.h"
#include "Playing_State.h"

namespace State
{
	Playing_State::Playing_State(Game & game) :
		Game_State(game)
	{
		// testing resource stuff. temp
		if (!music.openFromFile("Assets/Music/old_city_theme.ogg"))
		{
			printf("Music didn't load\n");
		}
		music.play();
		music.setLoop(true);
		
		shape.setTexture(&ResourceHolder::Instance().getTexture(TextureName::CHARACTERONE));


		shape.setSize(sf::Vector2f(64, 64));
		shape.setTextureRect(sf::IntRect(64 * 0, 64 * 2,64, 64));
		/////////////////////////////////////////////////////////////////
	}
	

	void Playing_State::Input()
	{

	}

	void Playing_State::Update(float dt)
	{

	}

	void Playing_State::Draw(sf::RenderWindow* window)
	{
		window->draw(shape);
	}
}
