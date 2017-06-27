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

	m_facingDirection = FacingDirection::DOWN;
	m_currentAction = ActionRow::WALKING;
}

void Player::Update(float dt)
{

	Input();
	m_sprite.setTextureRect(sf::IntRect(SPRITEDIMENSION * 4 /*static_cast<int>(m_currentAction)*/, 
										SPRITEDIMENSION * static_cast<int>(m_facingDirection),
										SPRITEDIMENSION, SPRITEDIMENSION));


}

void Player::Input()
{
	for (auto& keyValue : InputManager::Instance().GetKeysPressed())
	{
		switch (keyValue.first)
		{
		case sf::Keyboard::A:
			m_facingDirection = FacingDirection::LEFT;
			break;
		case sf::Keyboard::D:
			m_facingDirection = FacingDirection::RIGHT;
			break;
		case sf::Keyboard::W:
			m_facingDirection = FacingDirection::UP;
			break;
		case sf::Keyboard::S:
			m_facingDirection = FacingDirection::DOWN;
			break;
		default:
			break;
		}
	}
}

