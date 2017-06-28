#pragma once
#include "ObjectState.h"
#include "Player.h"



class StandingState : public ObjectState
{
public:
	static std::unique_ptr<StandingState> Instance();

	virtual void Enter	(CharacterObject& owner);
	virtual void Input	(CharacterObject& owner);
	virtual void Update	(CharacterObject& owner, float dt);
	virtual void Exit	(CharacterObject& owner);
};

class WalkingState : public ObjectState
{
public:
	static std::unique_ptr<WalkingState> Instance();

	virtual void Enter	(CharacterObject& owner);
	virtual void Input	(CharacterObject& owner);
	virtual void Update	(CharacterObject& owner, float dt);
	virtual void Exit	(CharacterObject& owner);
};