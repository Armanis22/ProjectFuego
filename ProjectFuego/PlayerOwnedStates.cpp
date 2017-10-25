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
	owner.SetVelocity({ 0, 0});
	owner.ResetStateCooldown();
}

void StandingState::Input(CharacterObject & owner)
{

	if (MouseManager::Instance().IsMouseRightPressed())
	{
		//owner.SetPosition(owner.CurrentPosition());
		owner.SetMoveDirection(MouseManager::Instance().MousePosition());
		owner.CalculateSpriteFacingDirection();
		owner.SetAcceleration(PLAYERACCELERATION);
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
	owner.GetAnimation().ClearFrames();
	printf("Entered Walking\n");
}

void WalkingState::Input(CharacterObject & owner)
{
	if (owner.GetDestination() == owner.CurrentPosition())
	{
		owner.GetFSM()->ChangeState(StandingState::Instance());
	}
	else
	{
		owner.CalculateSpriteFacingDirection();
	}
	if (MouseManager::Instance().IsMouseRightPressed())
	{
		
		owner.SetMoveDirection(MouseManager::Instance().MousePosition());
		owner.CalculateSpriteFacingDirection();
		owner.SetAcceleration(PLAYERACCELERATION);
	}
}

void WalkingState::Update(CharacterObject & owner, float dt)
{	
	//owner.ApplyDrag(dt);
	owner.CheckRangeToTarget(dt);
	//owner.LimitVelocity(dt);
	if (owner.GetPreviousFacing() != owner.GetFacingDirection())
	{
		owner.GetAnimation().ClearFrames();
	}
	owner.WalkAnimation();
	if (Vector2::Length(owner.DistanceToDestination()) < 1)
	{
		owner.GetFSM()->ChangeState(StandingState::Instance());
	}
	else
	{
		owner.MoveSprite(dt);
	}
	//owner.Update(dt);
}

void WalkingState::Exit(CharacterObject & owner)
{
	owner.GetAnimation().ClearFrames();
}
