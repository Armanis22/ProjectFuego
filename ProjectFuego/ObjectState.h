#pragma once
#include <memory>

class CharacterObject;


class ObjectState
{
public:
	ObjectState	() {};
	~ObjectState() {};

	virtual void Enter	(CharacterObject& owner)				= 0;
	virtual void Input	(CharacterObject& owner)				= 0;
	virtual void Update	(CharacterObject& owner, float dt)		= 0;
	virtual void Exit	(CharacterObject& owner)				= 0;

};

