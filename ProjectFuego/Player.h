#pragma once
#include "GameObject.h"


class Player :
	public GameObject
{
public:
	Player(sf::Vector2f pos);

	void Update(float dt);

	void Input();
private:


};

