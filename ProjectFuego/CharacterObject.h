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

	FacingDirection GetFacingDirection()					{ return m_facingDirection; }
	void			SetFacingDirection(FacingDirection dir) { m_facingDirection = dir; }
	void			SetPreviousFacing()						{ m_preciousFacingDirection = m_facingDirection; }
	FacingDirection	GetPreviousFacing()						{ return m_preciousFacingDirection; }

	std::unique_ptr<ObjectStateMachine>& GetFSM()			{ return m_StateMachine; }

	virtual Animation& GetAnimation	()						{ return m_animation; }
	void CreateAnimation			(FacingDirection direction, ActionRow row, ActionColumns column);

	void WalkAnimation();

	void MoveSprite(float dt);
	void SetMoveVector(float x, float y);

protected:

	std::unique_ptr<ObjectStateMachine> m_StateMachine;
	Animation m_animation;

	FacingDirection m_facingDirection;
	FacingDirection m_preciousFacingDirection;
	ActionRow m_currentAction;

	sf::Vector2f m_moveDirection;
};

