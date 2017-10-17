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
	void Update(float dt);

	FacingDirection GetFacingDirection()					{ return m_facingDirection; }
	void			SetFacingDirection(FacingDirection dir) { m_facingDirection = dir; }
	void			SetPreviousFacing()						{ m_previousFacingDirection = m_facingDirection; }
	FacingDirection	GetPreviousFacing()						{ return m_previousFacingDirection; }

	//New functions for steering behaviors
	//============================================================================
	sf::Vector2f Velocity() { return m_velocity; } //Grab current Velocity
	void SetVelocity(const sf::Vector2f vel) { m_velocity = vel; }

	float Mass() const { return m_mass; }
	float MaxSpeed() const { return m_maxSpeed; }
	float SetMaxSpeed(float newSpeed) { m_maxSpeed = newSpeed; }

	float MaxForce() const { return m_maxForce; }
	float SetMaxForce(float newForce) { m_maxForce = newForce; }

	float Speed() const { return Vector2::Length(m_velocity); }

	sf::Vector2f Heading() const { return m_heading; }
	void SetHeading(sf::Vector2f newHeading);

	sf::Vector2f SideVector() const { return m_sideVector; }

	float MaxTurnRate() const { return m_maxTurnRate; }
	void SetMaxTurnRate(float turn) { m_maxTurnRate = turn; }

	//=============================================================================

	// -bh
	// Functions for some of the physics aspects
	void SetAcceleration(float accel);
	void ApplyDrag(float dt);
	void LimitVelocity(float dt);
	void CheckRangeToTarget(float dt);


	void SetPosition(sf::Vector2f newPos) {
		m_sprite.setPosition(newPos);
		m_pos = m_sprite.getPosition();
	}

	std::unique_ptr<ObjectStateMachine>& GetFSM()			{ return m_StateMachine; }

	virtual Animation& GetAnimation	()						{ return m_animation; }
	void CreateAnimation			(FacingDirection direction, ActionRow row, ActionColumns column);

	void WalkAnimation();

	void MoveSprite(float dt);
	void SetMoveVector(float x, float y);
	void SetMoveDirection(sf::Vector2f newPosition);
	void CalculateFacingDirection();
	sf::Vector2f CurrentPosition() { return m_sprite.getPosition(); }
	sf::Vector2f GetDestination() { return m_moveDestination; }
	sf::Vector2f DistanceToDestination() { return m_moveDestination - m_sprite.getPosition(); }

protected:

	std::unique_ptr<ObjectStateMachine> m_StateMachine;
	Animation m_animation;

	FacingDirection m_facingDirection;
	FacingDirection m_previousFacingDirection;
	ActionRow m_currentAction;

	sf::Vector2f m_moveDirection;
	sf::Vector2f m_moveDestination;

	//New members for steering behaviors
	sf::Vector2f m_pos;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_velocity;
	sf::Vector2f m_heading;
	sf::Vector2f m_sideVector;

	float m_mass;
	float m_maxSpeed;
	float m_maxForce;
	float m_maxTurnRate;

};

