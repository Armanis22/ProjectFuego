#pragma once
#include "CharacterObject.h"

class SteeringBehaviors;

class Vehicle : public CharacterObject
{
public:
	Vehicle(sf::Vector2f pos);
	~Vehicle();

	void Update(float dt);

	SteeringBehaviors* const Steering() const { return m_steering; }

private:
	SteeringBehaviors* m_steering;
};

