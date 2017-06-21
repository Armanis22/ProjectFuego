#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	PushState(std::make_unique<State::Playing_State>(*this));
}


Game::~Game()
{
}

void Game::Update(float dt)
{
	m_states.top()->Input();
	m_states.top()->Update(dt);
}

void Game::Draw(sf::RenderWindow * window)
{
	for (unsigned int i = 0; i < m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->Draw(window);
	}
	m_states.top()->Draw(window);
}

void Game::AddObject(std::shared_ptr<GameObject> object)
{
	m_gameObjects.push_back(object);
}

void Game::PushState(std::unique_ptr<State::Game_State> state)
{
	m_states.push(std::move(state));
}

void Game::PopState()
{
	m_states.pop();
}

void Game::ChangeState(std::unique_ptr<State::Game_State> state)
{
	PopState();
	PushState(std::move(state));
}
