#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
}
