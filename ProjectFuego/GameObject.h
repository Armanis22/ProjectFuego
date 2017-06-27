#pragma once

#include "SFML\Graphics.hpp"
#include "InputHolder.h"
#include "ResourceHolder.h"

enum class FacingDirection
{
	UP = 1,
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

	void Draw(sf::RenderWindow* window);
	virtual void Update(float dt);

protected:
	sf::RectangleShape m_sprite;
};

