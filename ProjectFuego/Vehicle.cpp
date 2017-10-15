#include "stdafx.h"
#include "Vehicle.h"
#include "SteeringBehaviors.h"


Vehicle::Vehicle(sf::Vector2f pos) : CharacterObject::CharacterObject(pos)
{
	m_steering = new SteeringBehaviors(this);
}


Vehicle::~Vehicle()
{
}

void Vehicle::Update(float dt)
{
	//Basically a dumbed down version of Buckland's vehicle Update
	//Note: Steering->Calculate has not been implemented so big TODO
	sf::Vector2f OldPos = CurrentPosition();

	sf::Vector2f SteerForce;

	SteerForce = m_steering->Calculate();

	sf::Vector2f acceleration = SteerForce / m_mass;

	m_velocity += acceleration * dt;

	Vector2::Truncate(m_velocity, m_maxSpeed);

	CurrentPosition() += m_velocity * dt;
}
