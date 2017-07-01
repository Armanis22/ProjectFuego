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
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
}

void StandingState::Input(CharacterObject & owner)
{
	
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
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
		owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
	}
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
	case FacingDirection::RIGHT:
		owner.MoveSpriteRight(dt);
		break;
	case FacingDirection::UP:
		owner.MoveSpriteUp(dt);

		break;
	case FacingDirection::DOWN:
		owner.MoveSpriteDown(dt);
		break;
	case FacingDirection::LEFT:
		owner.MoveSpriteLeft(dt);
		break;

	default:
		break;
	}
	owner.WalkAnimation();
}

void WalkingState::Exit(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
}
