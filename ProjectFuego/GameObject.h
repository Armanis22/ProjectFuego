#pragma once

#include "SFML\Graphics.hpp"
#include "InputHolder.h"
#include "ResourceHolder.h"
#include "GlobalConsts.h"
#include "Animation.h"

enum class FacingDirection
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

enum class ActionRow
{
	CASTING = 0,
	THRUSTING = 4,
	WALKING = 8,
	SLASHING = 12,
	SHOOTING = 16,
	DYING = 20
};

enum class ActionColumns
{
	STANDING = 0,
	CASTING = 6,
	THRUSTING = 7,
	WALKING = 8,
	SLASHING = 5,
	SHOOTING = 12,
	DYING = 5
};


class GameObject
{
public:
	GameObject(sf::Vector2f pos);

	virtual void	Draw	(sf::RenderWindow* window);
	virtual void	Update	(float dt);

	FacingDirection GetFacingDirection()					{ return m_facingDirection; }
	void			SetFacingDirection(FacingDirection dir) { m_facingDirection = dir; }

	virtual Animation& GetAnimation() { return m_animation; }

protected:
	sf::RectangleShape m_sprite;
	Animation m_animation;

	FacingDirection m_facingDirection;
	ActionRow m_currentAction;


};

