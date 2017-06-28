#pragma once
#include "ObjectState.h"
#include "Player.h"



class StandingState : public ObjectState
{
public:
	static std::unique_ptr<StandingState> Instance();

	virtual void Enter	(GameObject& owner);
	virtual void Input	(GameObject& owner);
	virtual void Update	(GameObject& owner, float dt);
	virtual void Exit	(GameObject& owner);
};

class WalkingState : public ObjectState
{
public:
	static std::unique_ptr<WalkingState> Instance();

	virtual void Enter	(GameObject& owner);
	virtual void Input	(GameObject& owner);
	virtual void Update	(GameObject& owner, float dt);
	virtual void Exit	(GameObject& owner);
};