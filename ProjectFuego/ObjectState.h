#pragma once
#include <memory>

#include "GameObject.h"

class ObjectState
{
public:
	ObjectState	() {};
	~ObjectState() {};

	virtual void Enter	(GameObject& owner)				= 0;
	virtual void Input	(GameObject& owner)				= 0;
	virtual void Update	(GameObject& owner, float dt)	= 0;
	virtual void Exit	(GameObject& owner)				= 0;

};

