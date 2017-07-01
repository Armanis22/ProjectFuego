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

void CharacterObject::MoveSpriteUp(float dt)
{
	m_sprite.move({ 0,-MOVESPEED * dt });
}

void CharacterObject::MoveSpriteDown(float dt)
{
	m_sprite.move({ 0, MOVESPEED * dt });
}

void CharacterObject::MoveSpriteLeft(float dt)
{
	m_sprite.move({ -MOVESPEED * dt,0 });
}

void CharacterObject::MoveSpriteRight(float dt)
{
	m_sprite.move({ MOVESPEED * dt,0 });
}
