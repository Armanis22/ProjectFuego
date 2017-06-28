#pragma once
#include "Game_State.h"

namespace State
{
	class Playing_State : public Game_State
	{
	public:
		Playing_State(Game& game);

		void Input	()							override;
		void Update	(float dt)					override;
		void Draw	(sf::RenderWindow* window)	override;

	private:
		
		// temp shit for testing
		sf::RectangleShape shape;
		Animation animation;

	};

}