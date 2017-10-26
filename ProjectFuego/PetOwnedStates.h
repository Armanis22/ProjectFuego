#pragma once
#include "ObjectState.h"
#include "Pet.h"

class PetStandingState : public ObjectState
{
public:
	static PetStandingState* Instance();

	virtual void Enter(CharacterObject& owner);
	virtual void Input(CharacterObject& owner);
	virtual void Update(CharacterObject& owner, float dt);
	virtual void Exit(CharacterObject& owner);
};

class PetWalkingState : public ObjectState
{
public:
	static PetWalkingState* Instance();

	virtual void Enter(CharacterObject& owner);
	virtual void Input(CharacterObject& owner);
	virtual void Update(CharacterObject& owner, float dt);
	virtual void Exit(CharacterObject& owner);
};

class PetSeekState : public ObjectState
{
public:
	static PetSeekState* Instance();

	virtual void Enter(CharacterObject& owner);
	virtual void Input(CharacterObject& owner);
	virtual void Update(CharacterObject& owner, float dt);
	virtual void Exit(CharacterObject& owner);
};

class PetFollowState : public ObjectState
{
public:
	static PetFollowState* Instance();

	virtual void Enter(CharacterObject& owner);
	virtual void Input(CharacterObject& owner);
	virtual void Update(CharacterObject& owner, float dt);
	virtual void Exit(CharacterObject& owner);
};