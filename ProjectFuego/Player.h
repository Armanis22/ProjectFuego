#pragma once
#include "CharacterObject.h"
#include "ObjectStateMachine.h"
#include "PlayerOwnedStates.h"
#include "Pet.h"


class Player :
	public CharacterObject
{
public:
	Player(sf::Vector2f pos, Game* game);

	void Update(float dt);

	void Input();
	void AddPet(std::shared_ptr<Pet> pet);

private:
	std::vector<std::shared_ptr<Pet>> m_petList;
	float m_petSpawnCooldown;
};

