#include "stdafx.h"
#include "Game_State.h"
#include "Game.h"

namespace State
{

	Game_State::Game_State(Game & game) :
		m_p_game(&game)
	{
	}

	Game_State::~Game_State()
	{
	}
}