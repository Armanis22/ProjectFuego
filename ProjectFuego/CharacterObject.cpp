#include "stdafx.h"
#include "CharacterObject.h"


CharacterObject::CharacterObject(sf::Vector2f pos) :
	GameObject::GameObject(pos)
{
}

void CharacterObject::CreateAnimation(Animation & animation, FacingDirection direction, ActionRow row, ActionColumns column)
{
	int _row = static_cast<int>(direction) + static_cast<int>(row);
	for (int i = 1; i < static_cast<int>(column); i++)
	{
		animation.addFrame({ 64 * i,64 * _row,64,64 }, TIMETONEXTFRAME);
	}
}

void CharacterObject::WalkUpAnimation()
{
	CreateAnimation(m_animation, FacingDirection::UP, ActionRow::WALKING, ActionColumns::WALKING);
}

void CharacterObject::WalkDownAnimation()
{
	CreateAnimation(m_animation, FacingDirection::DOWN, ActionRow::WALKING, ActionColumns::WALKING);
}

void CharacterObject::WalkLeftAnimation()
{
	CreateAnimation(m_animation, FacingDirection::LEFT, ActionRow::WALKING, ActionColumns::WALKING);
}

void CharacterObject::WalkRightAnimation()
{
	CreateAnimation(m_animation, FacingDirection::RIGHT, ActionRow::WALKING, ActionColumns::WALKING);
}
