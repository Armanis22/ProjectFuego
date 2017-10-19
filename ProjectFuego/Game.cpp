#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Pet.h"



Game::Game()
{
	PushState(std::make_unique<State::Playing_State>(*this));
	AddObject(std::make_shared<Player>(sf::Vector2f(200, 200)));
	//AddObject(std::make_shared<Pet>(sf::Vector2f(300, 300), TextureName::SKELETON));


}

void Game::Update(float dt)
{
	m_states.top()->Input();
	m_states.top()->Update(dt);
	for (size_t i = 0; i < m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->Update(dt);
	}
}

void Game::Draw(sf::RenderWindow * window)
{
	for (size_t i = 0; i < m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->Draw(window);
	}
	m_states.top()->Draw(window);
}

void Game::AddObject(std::shared_ptr<GameObject> object)
{
	m_gameObjects.emplace_back(object);
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
