#pragma once
#include "ObjectState.h"
#include "Pet.h"

class AIStandingState : public ObjectState
{
public:
	static AIStandingState* Instance();

	virtual void Enter(CharacterObject& owner);
	virtual void Input(CharacterObject& owner);
	virtual void Update(CharacterObject& owner, float dt);
	virtual void Exit(CharacterObject& owner);
};

class AIWalkingState : public ObjectState
{
public:
	static AIWalkingState* Instance();

	virtual void Enter(CharacterObject& owner);
	virtual void Input(CharacterObject& owner);
	virtual void Update(CharacterObject& owner, float dt);
	virtual void Exit(CharacterObject& owner);
};
