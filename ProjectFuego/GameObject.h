#pragma once

#include "SFML\Graphics.hpp"
#include "Game.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Draw(sf::RenderWindow* window);

protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

