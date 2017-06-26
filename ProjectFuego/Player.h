#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player(Game& game, sf::Vector2f pos);

};

