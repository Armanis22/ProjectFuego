#include "stdafx.h"
#include "CharacterObject.h"


CharacterObject::CharacterObject(sf::Vector2f pos) :
	GameObject::GameObject(pos), 
	m_velocity(sf::Vector2f(0.f,0.f)), 
	//Below are temporary, will need to be setup (maybe lua) as mass and such will depend on the entity
	m_mass(10.0),
	m_heading(sf::Vector2f(0.f, 0.f)),
	m_maxForce(20.0),
	m_maxTurnRate(10.0)
{
	m_sprite.setOrigin(32, 32);
}

void CharacterObject::Update(float dt)
{
	/*m_velocity += m_acceleration * dt;

	LimitVelocity(dt);
	printf("(%f,%f)\n", m_velocity.x, m_velocity.y);
	m_pos += m_velocity * dt;
	m_sprite.setPosition(m_pos);*/
}

void CharacterObject::SetHeading(sf::Vector2f newHeading)
{
	m_heading = newHeading;

	//Move the side vector to account for the new heading
	m_sideVector = Vector2::Perp(m_heading);
}

void CharacterObject::SetAcceleration(float accel)
{
	//if (accel > 0)
	//{
		m_acceleration = sf::Vector2f({ accel + m_moveDirection.x, -accel + m_moveDirection.y });
	//}
}

void CharacterObject::ApplyDrag(float dt)
{
}

void CharacterObject::LimitVelocity(float dt)
{
}

void CharacterObject::CreateAnimation(FacingDirection direction, ActionRow row, ActionColumns column)
{
	int _row = static_cast<int>(direction) + static_cast<int>(row);
	for (int i = 1; i < static_cast<int>(column); i++)
	{
		m_animation.addFrame({ 64 * i,64 * _row,64,64 }, TIMETONEXTFRAME);
	}
}

void CharacterObject::WalkAnimation()
{
	CreateAnimation(m_facingDirection, ActionRow::WALKING, ActionColumns::WALKING);
}

void CharacterObject::MoveSprite(float dt)
{
	
	//m_sprite.move({ m_moveDirection.x * MOVESPEED * dt, m_moveDirection.y * MOVESPEED * dt });
	m_velocity += m_acceleration * dt;

	LimitVelocity(dt);
	m_pos += m_velocity * dt;
	m_sprite.setPosition(m_pos);

}

void CharacterObject::SetMoveVector(float x, float y)
{
	m_moveDirection = sf::Vector2f(x, y);
}

void CharacterObject::SetMoveDirection(sf::Vector2f newPosition)
{
	m_moveDestination = newPosition;
	m_moveDirection.x = m_moveDestination.x - m_sprite.getPosition().x;
	m_moveDirection.y = m_moveDestination.y - m_sprite.getPosition().y;
	Vector2::Normalize(m_moveDirection);
	printf("(%f,%f)\n", m_moveDirection.x, m_moveDirection.y);

}

void CharacterObject::CalculateFacingDirection()
{
	//printf("Normalized Direction: (%f,%f)\n", m_moveDirection.x, m_moveDirection.y);
	if (m_moveDirection.x > abs(m_moveDirection.y))
	{
		SetFacingDirection(FacingDirection::RIGHT);
	}
	else if (abs(m_moveDirection.x) > abs(m_moveDirection.y))
	{
		SetFacingDirection(FacingDirection::LEFT);
	}
	else if (m_moveDirection.y < 0)
	{
		SetFacingDirection(FacingDirection::UP);
	}
	else
	{
		SetFacingDirection(FacingDirection::DOWN);
	}
}

