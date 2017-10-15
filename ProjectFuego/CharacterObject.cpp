#include "stdafx.h"
#include "CharacterObject.h"


CharacterObject::CharacterObject(sf::Vector2f pos) :
	GameObject::GameObject(pos)
{
	m_sprite.setOrigin(32, 32);
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
	m_sprite.move({ m_moveDirection.x * MOVESPEED * dt, m_moveDirection.y * MOVESPEED * dt });

}

void CharacterObject::SetMoveVector(float x, float y)
{
	m_moveDirection = sf::Vector2f(x, y);
}

void CharacterObject::SetMoveDestination(sf::Vector2f newPosition)
{
	m_moveDistination = newPosition;
	m_moveDirection.x = m_moveDistination.x - m_sprite.getPosition().x;
	m_moveDirection.y = m_moveDistination.y - m_sprite.getPosition().y;
	Vector2::Normalize(m_moveDirection);
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

