#include "stdafx.h"
#include "PetOwnedStates.h"
#include <iostream>

//Right now a literal copy of the player owned state (exception of using left mouse for the time being)
//TODO:

//Set up some sort of AIController to handle steering behaviors for pets
//Beginning plan, to wander randomly but keep within a certain distance from the player
//Once enemy is added we'll need for pets to stay a certain larger distance but attack a nearby threat

PetStandingState* PetStandingState::Instance()
{
	static PetStandingState state;
	return &state;
}

void PetStandingState::Enter(CharacterObject & owner)
{
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);

}

void PetStandingState::Input(CharacterObject & owner)
{

	//This class should be taking commands from an AIController, TEMP

	/*if (MouseManager::Instance().IsMouseLeftPressed())
	{
		owner.SetMoveDirection(MouseManager::Instance().MousePosition());
		owner.CalculateSpriteFacingDirection();
		owner.GetFSM()->ChangeState(PetWalkingState::Instance());
	}*/

	
}

void PetStandingState::Update(CharacterObject & owner, float dt)
{
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
		owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
	}

	if (owner.DistanceToPlayer() >= 150)
	{
		owner.SetMoveDirection(owner.GetPlayerPosition());
		owner.CalculateSpriteFacingDirection();
		owner.SetAcceleration(PLAYERACCELERATION);
		owner.GetFSM()->ChangeState(PetFollowState::Instance());
	}
}

void PetStandingState::Exit(CharacterObject & owner)
{
	//owner.GetAnimation().ClearFrames();
}


// All things walking state
PetWalkingState* PetWalkingState::Instance()
{
	static PetWalkingState state;
	return &state;
}

void PetWalkingState::Enter(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
	printf("Entered Walking\n");
}

void PetWalkingState::Input(CharacterObject & owner)
{
	//This class should be taking commands from an AIController, TEMP

	if (owner.GetDestination() == owner.CurrentPosition())
	{
		owner.GetFSM()->ChangeState(PetStandingState::Instance());
	}

	else
	{
		owner.CalculateSpriteFacingDirection();
	}

	if (MouseManager::Instance().IsMouseLeftPressed())
	{
		owner.SetMoveDirection(MouseManager::Instance().MousePosition());
		owner.CalculateSpriteFacingDirection();
	}

}

void PetWalkingState::Update(CharacterObject & owner, float dt)
{
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
	}

	owner.WalkAnimation();

	if (Vector2::Length(owner.DistanceToDestination()) < 5)
	{
		printf("Distance %f\n", Vector2::Length(owner.DistanceToDestination()));
		owner.GetFSM()->ChangeState(PetStandingState::Instance());
	}

	else
	{
		owner.MoveSprite(dt);
	}
}

void PetWalkingState::Exit(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
}

PetSeekState* PetSeekState::Instance()
{
	static PetSeekState state;
	return &state;
}

void PetSeekState::Enter(CharacterObject& owner)
{

}

void PetSeekState::Input(CharacterObject& owner)
{
}

void PetSeekState::Update(CharacterObject& owner, float dt)
{
}

void PetSeekState::Exit(CharacterObject& owner)
{
}

PetFollowState * PetFollowState::Instance()
{
	static PetFollowState state;
	return &state;
}

void PetFollowState::Enter(CharacterObject & owner)
{
	//owner.GetAnimation().ClearFrames();
	printf("Entered Following\n");

}

void PetFollowState::Input(CharacterObject & owner)
{
}

void PetFollowState::Update(CharacterObject & owner, float dt)
{
	owner.CheckRangeToTarget(dt);
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
	}
	owner.SetMoveDirection(owner.GetPlayerPosition());
	owner.CalculateSpriteFacingDirection();
	owner.SetAcceleration(PLAYERACCELERATION);
	owner.WalkAnimation();
	if (Vector2::Length(owner.DistanceToDestination()) < 100)
	{
		owner.GetFSM()->ChangeState(PetStandingState::Instance());
	}
	else
	{
		owner.MoveSprite(dt);
	}
}

void PetFollowState::Exit(CharacterObject & owner)
{
}
