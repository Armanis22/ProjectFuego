#pragma once
#include "GameObject.h"
#include "ObjectStateMachine.h"

enum class FacingDirection
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

enum class ActionRow
{
	CASTING = 0,
	THRUSTING = 4,
	WALKING = 8,
	SLASHING = 12,
	SHOOTING = 16,
	DYING = 20
};

enum class ActionColumns
{
	STANDING = 0,
	CASTING = 6,
	THRUSTING = 7,
	WALKING = 8,
	SLASHING = 5,
	SHOOTING = 12,
	DYING = 5
};


class CharacterObject :
	public GameObject
{
public:
	CharacterObject(sf::Vector2f pos);

	FacingDirection GetFacingDirection()			{ return m_facingDirection; }
	void			SetFacingDirection(FacingDirection dir) { m_facingDirection = dir; }
	void			SetPreviousFacing()				{ m_preciousFacingDirection = m_facingDirection; }
	FacingDirection	GetPreviousFacing()				{ return m_preciousFacingDirection; }

	std::unique_ptr<ObjectStateMachine>& GetFSM()	{ return m_StateMachine; }

	virtual Animation& GetAnimation	()				{ return m_animation; }
	void CreateAnimation			(Animation& animation, FacingDirection direction, ActionRow row, ActionColumns column);

	void WalkUpAnimation();
	void WalkDownAnimation();
	void WalkLeftAnimation();
	void WalkRightAnimation();


protected:

	std::unique_ptr<ObjectStateMachine> m_StateMachine;
	Animation m_animation;
	Animation m_walkUp;
	Animation m_walkDown;
	Animation m_walkLeft;
	Animation m_walkRight;
	

	FacingDirection m_facingDirection;
	FacingDirection m_preciousFacingDirection;
	ActionRow m_currentAction;

};

