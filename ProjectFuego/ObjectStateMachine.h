#pragma once
#include "ObjectState.h"
#include <stack>


class ObjectStateMachine
{
private:
	CharacterObject& m_Owner;
	std::stack<std::unique_ptr<ObjectState>> m_stateStack;

public:

	ObjectStateMachine (CharacterObject& owner) :
		m_Owner(owner)
	{}

	~ObjectStateMachine() {};

	void SetCurrentState() {};

	void Update(float dt) const
	{
		if (m_stateStack.top())
		{
			m_stateStack.top()->Update(m_Owner, dt);
		}
	}

	void Input() const
	{
		if (m_stateStack.top())
		{
			m_stateStack.top()->Input(m_Owner);
		}
	}

	void ChangeState(std::unique_ptr<ObjectState> newState)
	{
		if (m_stateStack.top())
		{
			m_stateStack.top()->Exit(m_Owner);
			m_stateStack.pop();
		}
		m_stateStack.emplace(std::move(newState));
		m_stateStack.top()->Enter(m_Owner);
	}

	void PushState(std::unique_ptr<ObjectState> pushingState)
	{
		m_stateStack.emplace(std::move(pushingState));
		m_stateStack.top()->Enter(m_Owner);
	}
	void PopState()
	{
		m_stateStack.pop();
	}
};