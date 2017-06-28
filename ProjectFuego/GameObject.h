#pragma once

#include <memory>
#include "SFML\Graphics.hpp"
#include "InputHolder.h"
#include "ResourceHolder.h"
#include "GlobalConsts.h"
#include "Animation.h"

class GameObject
{
public:
	GameObject(sf::Vector2f pos);

	virtual void	Update	(float dt);
	virtual void	Draw	(sf::RenderWindow* window) = 0;

protected:
	sf::RectangleShape m_sprite;

};

