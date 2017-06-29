#include "stdafx.h"
#include "PlayerOwnedStates.h"

// all things standing still
StandingState* StandingState::Instance()
{
	static StandingState state;
	return &state;
}

void StandingState::Enter(CharacterObject & owner)
{
	printf("Entered playing state\n");
	owner.GetAnimation().ClearFrames();
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
}

void StandingState::Input(CharacterObject & owner)
{
	for (auto& keyValue : InputManager::Instance().GetKeysPressed())
	{
		switch (keyValue.first)
		{
		case sf::Keyboard::A:
			owner.SetFacingDirection(FacingDirection::LEFT);
			owner.GetFSM()->ChangeState(WalkingState::Instance());
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

void StandingState::Update(CharacterObject & owner, float dt)
{
	owner.GetAnimation().ClearFrames();
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
}

void StandingState::Exit(CharacterObject & owner)
{
}


// All things walking state


WalkingState* WalkingState::Instance()
{
	static WalkingState state;
	return &state;
}

void WalkingState::Enter(CharacterObject & owner)
{
	printf("Entered walking state\n");
	owner.GetAnimation().ClearFrames();
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);

}

void WalkingState::Input(CharacterObject & owner)
{
	for (auto& keyValue : InputManager::Instance().GetKeysPressed())
	{
		switch (keyValue.first)
		{
	
		case sf::Keyboard::D:
			owner.GetFSM()->ChangeState(StandingState::Instance());
			break;
		
		default:
			break;
		}
	}
}

void WalkingState::Update(CharacterObject & owner, float dt)
{

}

void WalkingState::Exit(CharacterObject & owner)
{

}
