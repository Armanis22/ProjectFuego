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
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
}

void StandingState::Input(CharacterObject & owner)
{

	if (MouseManager::Instance().IsMouseRightPressed())
	{
		owner.SetMoveDestination(MouseManager::Instance().MousePosition());
		owner.CalculateFacingDirection();
		
		//owner.GetFSM()->ChangeState(WalkingState::Instance());
	}


	/*
	------ Old WASD movement stuff

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		owner.GetFSM()->ChangeState(WalkingState::Instance());
	}*/
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
	switch (owner.GetFacingDirection())
	{
	case FacingDirection::RIGHT:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			owner.SetMoveVector(MOVEDIAG, -MOVEDIAG);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			owner.SetMoveVector(MOVEDIAG, MOVEDIAG);
		}
		else
		{
			owner.SetMoveVector(MOVESPEED, 0);
		}
		break;
	case FacingDirection::LEFT:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			owner.SetMoveVector(-MOVEDIAG, -MOVEDIAG);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			owner.SetMoveVector(-MOVEDIAG, MOVEDIAG);
		}
		else
		{
			owner.SetMoveVector(-MOVESPEED, 0);
		}
		break;
	case FacingDirection::UP:
		owner.SetMoveVector(0, -MOVESPEED);
		break;
	case FacingDirection::DOWN:
		owner.SetMoveVector(0, MOVESPEED);
		break;

	default:
		owner.SetMoveVector(0, 0);
		break;
	}
}

void WalkingState::Update(CharacterObject & owner, float dt)
{	
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
	}
	owner.WalkAnimation();
	owner.MoveSprite(dt);
}

void WalkingState::Exit(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
}
