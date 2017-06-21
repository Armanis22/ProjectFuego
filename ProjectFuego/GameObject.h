#pragma once

#include "SFML\Graphics.hpp"
#include "Game.h"

class GameObject
{
public:
	GameObject(Game& game, sf::Vector2f pos);
	~GameObject();

	void Draw(sf::RenderWindow* window);
	void Update(float dt);

protected:
	sf::RectangleShape m_sprite;
	sf::Texture m_texture;

	std::unique_ptr<Game> m_p_game;

	
};

