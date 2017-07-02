#include "stdafx.h"
#include "CharacterObject.h"


CharacterObject::CharacterObject(sf::Vector2f pos) :
	GameObject::GameObject(pos)
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
	m_sprite.move({ m_moveDirection.x * dt, m_moveDirection.y * dt });

}

void CharacterObject::SetMoveVector(float x, float y)
{
	m_moveDirection = sf::Vector2f(x, y);
}

