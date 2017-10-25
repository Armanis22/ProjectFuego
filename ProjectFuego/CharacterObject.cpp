#include "stdafx.h"
#include "CharacterObject.h"


CharacterObject::CharacterObject(sf::Vector2f pos) :
	GameObject::GameObject(pos),
	m_velocity(sf::Vector2f(0.f, 0.f)),
	//Below are temporary, will need to be setup (maybe lua) as mass and such will depend on the entity
	m_mass(10.0),
	m_heading(sf::Vector2f(0.f, 0.f)),
	m_maxForce(20.0),
	m_maxTurnRate(10.0),
	m_isDestroyed(false),
	m_pos(pos),
	m_stateChangeCooldown(.0f)
{
	m_sprite.setOrigin(32, 32);
}

CharacterObject::CharacterObject(sf::Vector2f pos, Game* game) :
	GameObject::GameObject(pos),
	m_velocity(sf::Vector2f(0.f, 0.f)),
	//Below are temporary, will need to be setup (maybe lua) as mass and such will depend on the entity
	m_mass(10.0),
	m_heading(sf::Vector2f(0.f, 0.f)),
	m_maxForce(20.0),
	m_maxTurnRate(10.0),
	m_isDestroyed(false),
	m_pos(pos),
	m_pGameManager(game)
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
	//printf("(%f,%f)\n", m_moveDirection.x, m_moveDirection.y);

	m_acceleration = sf::Vector2f({ accel * m_moveDirection.x, accel * m_moveDirection.y });
	//}
}

void CharacterObject::ApplyDrag(float dt)
{
	float _friction = 5.f;
	sf::Vector2f _drag = _friction * m_velocity * dt;
	m_velocity -= _drag;
}

void CharacterObject::LimitVelocity(float dt)
{
	float _speed = Vector2::Length(m_velocity);

	if (_speed <= .001)
	{
		_speed = 0;
	}

	if (_speed > MAXMOVESPEED)
	{
		_speed = MAXMOVESPEED;
	}

	m_velocity = m_moveDirection * _speed;
}

void CharacterObject::CheckRangeToTarget(float dt)
{
	if ( Vector2::LengthSq(m_moveDestination - m_pos) < 1200)
	{
		ApplyDrag(dt);
		SetAcceleration(0);
	}
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

}

void CharacterObject::CalculateSpriteFacingDirection()
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

