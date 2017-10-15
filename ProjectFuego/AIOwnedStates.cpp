#include "stdafx.h"
#include "AIOwnedStates.h"
#include <iostream>

//Right now a literal copy of the player owned state (exception of using left mouse for the time being)
//TODO:

//Set up some sort of AIController to handle steering behaviors for pets
//Beginning plan, to wander randomly but keep within a certain distance from the player
//Once enemy is added we'll need for pets to stay a certain larger distance but attack a nearby threat

AIStandingState* AIStandingState::Instance()
{
	static AIStandingState state;
	return &state;
}

void AIStandingState::Enter(CharacterObject & owner)
{
	owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
}

void AIStandingState::Input(CharacterObject & owner)
{

	//This class should be taking commands from an AIController, TEMP

	if (MouseManager::Instance().IsMouseLeftPressed())
	{
		owner.SetMoveDestination(MouseManager::Instance().MousePosition());
		owner.CalculateFacingDirection();
		owner.GetFSM()->ChangeState(AIWalkingState::Instance());
	}

	
}

void AIStandingState::Update(CharacterObject & owner, float dt)
{
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
		owner.GetAnimation().addFrame({ 0,64 * static_cast<int>(owner.GetFacingDirection()),64,64 }, .1f);
	}
}

void AIStandingState::Exit(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
}


// All things walking state
AIWalkingState* AIWalkingState::Instance()
{
	static AIWalkingState state;
	return &state;
}

void AIWalkingState::Enter(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
	printf("Entered Walking\n");
}

void AIWalkingState::Input(CharacterObject & owner)
{
	//This class should be taking commands from an AIController, TEMP

	if (owner.GetDestination() == owner.CurrentPosition())
	{
		owner.GetFSM()->ChangeState(AIStandingState::Instance());
	}

	else
	{
		owner.CalculateFacingDirection();
	}

	if (MouseManager::Instance().IsMouseLeftPressed())
	{
		owner.SetMoveDestination(MouseManager::Instance().MousePosition());
		owner.CalculateFacingDirection();
	}

}

void AIWalkingState::Update(CharacterObject & owner, float dt)
{
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
	}

	owner.WalkAnimation();

	if (Vector2::Length(owner.DistanceToDestination()) < 5)
	{
		printf("Distance %f\n", Vector2::Length(owner.DistanceToDestination()));
		owner.GetFSM()->ChangeState(AIStandingState::Instance());
	}

	else
	{
		owner.MoveSprite(dt);
	}
}

void AIWalkingState::Exit(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
}

AISeekState* AISeekState::Instance()
{
	static AISeekState state;
	return &state;
}

void AISeekState::Enter(CharacterObject& owner)
{

}

void AISeekState::Input(CharacterObject& owner)
{
}

void AISeekState::Update(CharacterObject& owner, float dt)
{
}

void AISeekState::Exit(CharacterObject& owner)
{
}

