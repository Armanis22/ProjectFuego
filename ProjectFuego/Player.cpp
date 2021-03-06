#include "stdafx.h"
#include "Player.h"


Player::Player(sf::Vector2f pos, Game* game) :
	CharacterObject::CharacterObject(pos, game),
	m_petSpawnCooldown(PETSPAWNCOOLDOWN)
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

	m_moveDirection = sf::Vector2f(0, 1);
}

void Player::Update(float dt)
{
	Input();
	GetFSM()->Update(dt);
	if(m_petList.size() > 0)
	{
		for (size_t i = 0; i < m_petList.size(); i++)
		{
			//printf("%f\n", m_pos.x);

			m_petList[i]->SetPlayerPosition(m_pos);
		}
	}
	m_sprite.setTextureRect(m_animation.getFrame(dt));
	SetPreviousFacing();
	m_petSpawnCooldown += dt;
	m_stateChangeCooldown += dt;
}

void Player::Input()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_petSpawnCooldown >= PETSPAWNCOOLDOWN)
	{
		//Game::Instance()->AddObject(std::make_shared<Pet>(sf::Vector2f(300, 300), TextureName::SKELETON));
		AddPet(std::make_shared<Pet>(sf::Vector2f(100,100), m_pGameManager, this));
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
	pet->SetPosition(_spawnPosition);
	m_pGameManager->AddObject(pet);
	m_petList.emplace_back(pet);
		
}

