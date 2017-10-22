#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Pet.h"



Game::Game()
{
	PushState(std::make_unique<State::Playing_State>(*this));
	AddObject(std::make_shared<Player>(sf::Vector2f(200, 200), this));
	//AddObject(std::make_shared<Pet>(sf::Vector2f(300, 300), TextureName::SKELETON));
}

void Game::Update(float dt)
{
	m_states.top()->Input();
	m_states.top()->Update(dt);
	for (size_t i = 0; i < m_gameObjects.size(); ++i)
	{
		if ((i+1) < m_gameObjects.size() &&
			m_gameObjects[i]->GetYPosition() > m_gameObjects[i + 1]->GetYPosition())
		{
			auto _temp = m_gameObjects[i];
			m_gameObjects[i] = m_gameObjects[i + 1];
			m_gameObjects[i + 1] = _temp;
		}
		m_gameObjects[i]->Update(dt);
	}

	/*if (m_gameObjects.size() > 2)
	{
		QuickSort(0, m_gameObjects.size());
	}*/
	
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
	puts("called");
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

void Game::QuickSort(int left, int right)
{
	// left and right are the outter most indexes
	// temp for later. Index is just a calculation for the
	//	pivot point
	int i = left;
	int j = right;

	int index = (left + right) / 2;
	int bleck = m_gameObjects[i]->GetYPosition();
	int pivot = m_gameObjects[index]->GetYPosition();

	// partition
	// as long as i is less than j then
	// left is still left of right.
	// find i and j that are on the wrong side of the pivot
	while (i <= j)
	{
		while (m_gameObjects[i]->GetYPosition() < pivot)
		{
			i++;
		}

		while (m_gameObjects[j]->GetYPosition() > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			auto _temp = m_gameObjects[i];
			m_gameObjects[i] = m_gameObjects[i + 1];
			m_gameObjects[i + 1] = _temp;
			i++;
			j--;
		}

	}
	//recursively call itself 
	if (left < j)
	{
		QuickSort(left, j);
	}
	if (i < right)
	{
		QuickSort(i, right);
	}


}

