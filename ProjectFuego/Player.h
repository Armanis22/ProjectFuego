#pragma once
#include "GameObject.h"
#include "ObjectStateMachine.h"
#include "PlayerOwnedStates.h"


class Player :
	public GameObject
{
public:
	Player(sf::Vector2f pos);
	
	void Draw(sf::RenderWindow* window);
	void Update(float dt);

	void Input();

	std::unique_ptr<ObjectStateMachine>& GetFSM() { return m_StateMachine; }

	virtual Animation& GetAnimation() { return m_animation; }

private:

	std::unique_ptr<ObjectStateMachine> m_StateMachine;
};

