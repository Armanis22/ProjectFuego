#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(Game& game, sf::Vector2f pos)
{
	m_sprite.setTexture(&ResourceHolder::Instance().getTexture(TextureName::CHARACTERONE));
	m_sprite.setPosition(pos);

	m_sprite.setSize(sf::Vector2f(64, 64));
	m_sprite.setTextureRect(sf::IntRect(64 * 0, 64 * 2, 64, 64));
	m_sprite.setScale(4, 4);
}


GameObject::~GameObject()
{
}

void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
}

void GameObject::Update(float dt)
{
}
