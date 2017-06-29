#pragma once
#include "ObjectState.h"
#include <stack>


class ObjectStateMachine
{
private:
	CharacterObject& m_Owner;
	ObjectState* m_pCurrentState;
	ObjectState* m_pPreviousState;

public:

	ObjectStateMachine(CharacterObject& owner) :
		m_Owner(owner),
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr)
	{}

	~ObjectStateMachine() {};

	void SetCurrentState(ObjectState* state) 
	{
		m_pCurrentState = state;
		m_pCurrentState->Enter(m_Owner);
	}

	void SetPreviousState(ObjectState* state) { m_pPreviousState = state; }

	void Update(float dt) const
	{
		if (m_pCurrentState)
		{
			m_pCurrentState->Update(m_Owner, dt);
		}
	}

	void Input() const
	{
		if (m_pCurrentState)
		{
			m_pCurrentState->Input(m_Owner);
		}
	}

	void ChangeState(ObjectState* newState)
	{
		m_pPreviousState = m_pCurrentState;

		m_pCurrentState->Exit(m_Owner);
		m_pCurrentState = newState;
		m_pCurrentState->Enter(m_Owner);
	}

	void PopState()
	{
		m_pCurrentState = m_pPreviousState;
	}
};