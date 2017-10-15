#pragma once
#include "SFML\Graphics.hpp"
#include "Vector2.h"

class CharacterObject;
class Vehicle;

class SteeringBehaviors
{
public:
	SteeringBehaviors(Vehicle* agent);
	~SteeringBehaviors();

	void SetTarget(const sf::Vector2f target) { m_currentTarget = target; }

	void SetTargetVehicle(Vehicle* target) { m_targetVehicle = target; }

	sf::Vector2f Force() const { return m_steeringForce; }

	sf::Vector2f Calculate();

private:

	//A pointer to the controlling character (Pet/Monster)
	Vehicle* m_AIController;

	sf::Vector2f m_steeringForce;

	//Pointer to a target
	Vehicle* m_targetVehicle;

	//Currently set target position
	sf::Vector2f m_currentTarget;

	//Move towards a target position
	sf::Vector2f Seek(sf::Vector2f TargetPos);

	//Makes unit slow before arriving so stops aren't abrupt
	sf::Vector2f Arrive(sf::Vector2f TargetPos);

	//Used for chasing down enemies
	sf::Vector2f Pursuit(const CharacterObject* agent);

	//this behavior makes the agent wander about randomly
	sf::Vector2f Wander();
};

