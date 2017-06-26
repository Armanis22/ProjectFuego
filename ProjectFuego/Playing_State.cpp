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
		music.play();
		music.setLoop(true);
		
		shape.setTexture(&ResourceHolder::Instance().getTexture(TextureName::CHARACTERONE));
		
		shape.setSize(sf::Vector2f(64, 64));
		//shape.setTextureRect(sf::IntRect(64 * 0, 64 * 2,64, 64));
		shape.setScale(5, 5);
		
		//animation.addFrame({ 64 * 0,64 * 10,64,64 }, TIMETONEXTFRAME);
		animation.addFrame({ 64 * 1,64 * 10,64,64 }, TIMETONEXTFRAME);
		animation.addFrame({ 64 * 2,64 * 10,64,64 }, TIMETONEXTFRAME);
		animation.addFrame({ 64 * 3,64 * 10,64,64 }, TIMETONEXTFRAME);
		animation.addFrame({ 64 * 4,64 * 10,64,64 }, TIMETONEXTFRAME);
		animation.addFrame({ 64 * 5,64 * 10,64,64 }, TIMETONEXTFRAME);
		animation.addFrame({ 64 * 6,64 * 10,64,64 }, TIMETONEXTFRAME);
		animation.addFrame({ 64 * 7,64 * 10,64,64 }, TIMETONEXTFRAME);
		animation.addFrame({ 64 * 8,64 * 10,64,64 }, TIMETONEXTFRAME);

		/////////////////////////////////////////////////////////////////

	}
	

	void Playing_State::Input()
	{

	}

	void Playing_State::Update(float dt)
	{
		shape.setTextureRect(animation.getFrame(dt));
	}

	void Playing_State::Draw(sf::RenderWindow* window)
	{
		window->draw(shape);
		
	}
}
