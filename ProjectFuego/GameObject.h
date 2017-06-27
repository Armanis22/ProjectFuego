#pragma once

#include "SFML\Graphics.hpp"
#include "Game.h"

enum class FacingDirection
{
	UP = 1,
	LEFT,
	DOWN,
	RIGHT
};

enum class CurrentAction
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

