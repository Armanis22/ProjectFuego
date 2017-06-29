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
	printf("entered standing\n");

	//owner.GetAnimation().ClearFrames();
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
}

void StandingState::Input(CharacterObject & owner)
{
	/*for (auto& keyValue : InputManager::Instance().GetKeysPressed())
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
			owner.GetFSM()->ChangeState(WalkingState::Instance());

			break;
		case sf::Keyboard::S:
			owner.SetFacingDirection(FacingDirection::DOWN);
			break;
		default:
			break;
		}
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		owner.GetFSM()->ChangeState(WalkingState::Instance());
	}
}

void StandingState::Update(CharacterObject & owner, float dt)
{
	owner.GetAnimation().ClearFrames();
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
}

void StandingState::Exit(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
}


// All things walking state


WalkingState* WalkingState::Instance()
{
	static WalkingState state;
	return &state;
}

void WalkingState::Enter(CharacterObject & owner)
{
	printf("entered walking\n");

	owner.GetAnimation().ClearFrames();

}

void WalkingState::Input(CharacterObject & owner)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		)
	{
		owner.GetFSM()->ChangeState(StandingState::Instance());
	}
}

void WalkingState::Update(CharacterObject & owner, float dt)
{	
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
	}
	switch (owner.GetFacingDirection())
	{
	case FacingDirection::UP:
		owner.WalkUpAnimation();
		break;
	case FacingDirection::DOWN:
		owner.WalkDownAnimation();
		break;
	case FacingDirection::LEFT:
		owner.WalkLeftAnimation();
		break;
	case FacingDirection::RIGHT:
		owner.WalkRightAnimation();
		break;

	default:
		break;
	}
}

void WalkingState::Exit(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
}
