#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(sf::Vector2f pos)
{
	
}

void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
}

void GameObject::Update(float dt)
{
	
}
