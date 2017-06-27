#include "stdafx.h"
#include "Player.h"


Player::Player(sf::Vector2f pos) :
	GameObject::GameObject(pos)
{
	m_sprite.setTexture(&ResourceHolder::Instance().getTexture(TextureName::CHARACTERONE));
	m_sprite.setPosition(pos);

	m_sprite.setSize(sf::Vector2f(64, 64));
	m_sprite.setTextureRect(sf::IntRect(64 * 0, 64 * 2, 64, 64));
	m_sprite.setScale(4, 4);
}

void Player::Update(float dt)
{

	Input();
}

void Player::Input()
{

}

