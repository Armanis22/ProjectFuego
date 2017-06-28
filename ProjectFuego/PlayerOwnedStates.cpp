#include "stdafx.h"
#include "PlayerOwnedStates.h"

// all things standing still
std::unique_ptr<StandingState> StandingState::Instance()
{
	static std::unique_ptr<StandingState> state = std::make_unique<StandingState>();
	return std::move(state);
}

void StandingState::Enter(GameObject & owner)
{
}

void StandingState::Input(GameObject & owner)
{
	for (auto& keyValue : InputManager::Instance().GetKeysPressed())
	{
		switch (keyValue.first)
		{
		case sf::Keyboard::A:
			owner.SetFacingDirection(FacingDirection::LEFT);
			break;
		case sf::Keyboard::D:
			owner.SetFacingDirection(FacingDirection::RIGHT);
			break;
		case sf::Keyboard::W:
			owner.SetFacingDirection(FacingDirection::UP);
			break;
		case sf::Keyboard::S:
			owner.SetFacingDirection(FacingDirection::DOWN);
			break;
		default:
			break;
		}
	}
}

void StandingState::Update(GameObject & owner, float dt)
{
}

void StandingState::Exit(GameObject & owner)
{
}


// All things walking state


std::unique_ptr<WalkingState> WalkingState::Instance()
{
	static std::unique_ptr<WalkingState> state = std::make_unique<WalkingState>();
	return std::move(state);
}

void WalkingState::Enter(GameObject & owner)
{
}

void WalkingState::Input(GameObject & owner)
{
}

void WalkingState::Update(GameObject & owner, float dt)
{
}

void WalkingState::Exit(GameObject & owner)
{
}
