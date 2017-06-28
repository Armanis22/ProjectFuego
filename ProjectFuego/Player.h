#pragma once
#include "GameObject.h"
#include "ObjectStateMachine.h"
#include "PlayerOwnedStates.h"


class Player :
	public GameObject
{
public:
	Player(sf::Vector2f pos);
	
	void Update(float dt);

	void Input();

	std::unique_ptr<ObjectStateMachine>& GetFSM() { return m_StateMachine; }

private:

	std::unique_ptr<ObjectStateMachine> m_StateMachine;
};

