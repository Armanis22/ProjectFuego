#include "stdafx.h"
#include "Player.h"


Player::Player(sf::Vector2f pos) :
	CharacterObject::CharacterObject(pos)
{
	m_StateMachine = std::make_unique<ObjectStateMachine>(*this);
	m_sprite.setTexture(&ResourceHolder::Instance().getTexture(TextureName::CHARACTERONE));
	m_sprite.setPosition(pos);

	m_sprite.setSize(sf::Vector2f(64, 64));
	m_sprite.setTextureRect(sf::IntRect(64 * 0, 64 * 3, 64, 64));
	m_sprite.setScale(4, 4);

	m_facingDirection = FacingDirection::DOWN;
	m_currentAction = ActionRow::WALKING;
	m_StateMachine->SetCurrentState(StandingState::Instance());

}

void Player::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
}

void Player::Update(float dt)
{

	Input();
	GetFSM()->Update(dt);
	m_sprite.setTextureRect(m_animation.getFrame(dt)); 
	//GetFSM()->PushState(WalkingState::Instance());

}

void Player::Input()
{
	GetFSM()->Input();
}

