#pragma once
#include "CharacterObject.h"
#include "ObjectStateMachine.h"
#include "PlayerOwnedStates.h"


class Player :
	public CharacterObject
{
public:
	Player(sf::Vector2f pos);
	
	void Draw(sf::RenderWindow* window);
	void Update(float dt);

	void Input();

	virtual Animation& GetAnimation() { return m_animation; }

private:

};

