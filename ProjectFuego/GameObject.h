#pragma once

#include <memory>
#include "SFML\Graphics.hpp"
#include "MouseManager.h"
#include "ResourceHolder.h"
#include "GlobalConsts.h"
#include "Animation.h"
#include "Vector2.h"
#include "Game.h"

class GameObject
{
public:
	GameObject(sf::Vector2f pos);
	GameObject(sf::Vector2f pos, Game* game);

	virtual void	Update	(float dt) = 0;
	virtual void	Draw	(sf::RenderWindow* window);

protected:
	sf::RectangleShape m_sprite;
};

