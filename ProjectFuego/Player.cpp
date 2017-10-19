#include "stdafx.h"
#include "Player.h"


Player::Player(sf::Vector2f pos, Game* game) :
	CharacterObject::CharacterObject(pos, game),
	m_petSpawnCooldown(2)
{
	m_StateMachine = std::make_unique<ObjectStateMachine>(*this);
	m_sprite.setTexture(&ResourceHolder::Instance().getTexture(TextureName::CHARACTERONE));
	m_sprite.setPosition(pos);

	m_sprite.setSize(sf::Vector2f(64, 64));
	//m_sprite.setTextureRect(sf::IntRect(64 * 0, 64 * 3, 64, 64));
	m_sprite.setScale(2, 2);

	m_facingDirection = FacingDirection::UP;
	m_currentAction = ActionRow::WALKING;
	m_StateMachine->SetCurrentState(StandingState::Instance());

}

void Player::Update(float dt)
{
	Input();
	GetFSM()->Update(dt);
	m_sprite.setTextureRect(m_animation.getFrame(dt));
	SetPreviousFacing();
	m_petSpawnCooldown += dt;
}

void Player::Input()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_petSpawnCooldown >= 2)
	{
		//Game::Instance()->AddObject(std::make_shared<Pet>(sf::Vector2f(300, 300), TextureName::SKELETON));
		AddPet(std::make_shared<Pet>(sf::Vector2f(100,100), TextureName::SKELETON));
		m_petSpawnCooldown = 0;
	}
	
	GetFSM()->Input();
}

void Player::AddPet(std::shared_ptr<Pet> pet)
{
	sf::Vector2f _spawnPosition;
	switch (GetFacingDirection())
	{
	case FacingDirection::UP:
		_spawnPosition = sf::Vector2f(m_pos.x,m_pos.y - 100);
		break;
	case FacingDirection::DOWN:
		_spawnPosition = sf::Vector2f(m_pos.x, m_pos.y + 100);
		break;
	case FacingDirection::LEFT:
		_spawnPosition = sf::Vector2f(m_pos.x - 100, m_pos.y);
		break;
	case FacingDirection::RIGHT:
		_spawnPosition = sf::Vector2f(m_pos.x + 100, m_pos.y);
		break;
	default:
		break;
	}
	//puts("called");
	pet->SetPosition(_spawnPosition);
	m_pGameManager->AddObject(pet);
	//m_petList.emplace_back(pet);
		
}

