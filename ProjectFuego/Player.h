#pragma once
#include "CharacterObject.h"
#include "ObjectStateMachine.h"
#include "PlayerOwnedStates.h"


class Player :
	public CharacterObject
{
public:
	Player(sf::Vector2f pos);

	void Update(float dt);

	void Input();
	void AddPet();

private:
	std::vector<std::shared_ptr<Pet>> m_petList;

};

