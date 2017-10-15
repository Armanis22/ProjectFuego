#include "stdafx.h"
#include "SteeringBehaviors.h"
#include "Vehicle.h"


SteeringBehaviors::SteeringBehaviors(Vehicle* agent) :
	m_AIController(agent),
	m_targetVehicle(nullptr)

{
}


SteeringBehaviors::~SteeringBehaviors()
{
}

sf::Vector2f SteeringBehaviors::Calculate()
{
	Vector2::Zero(m_steeringForce);

	return sf::Vector2f();
}

sf::Vector2f SteeringBehaviors::Seek(sf::Vector2f TargetPos)
{
	sf::Vector2f desiredVelocity = Vector2::Normalize(TargetPos - m_AIController->CurrentPosition()) * m_AIController->MaxSpeed();
	return (desiredVelocity - m_AIController->Velocity());
}

sf::Vector2f SteeringBehaviors::Arrive(sf::Vector2f TargetPos)
{
	//Implement
	return sf::Vector2f();
}

sf::Vector2f SteeringBehaviors::Pursuit(const CharacterObject * agent)
{
	//Implement
	return sf::Vector2f();
}

sf::Vector2f SteeringBehaviors::Wander()
{
	//Implement
	return sf::Vector2f();
}
