#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <memory>
#include <stack>
#include "Game_State.h"
#include "Playing_State.h"
#include "GameObject.h"

#include "ResourceHolder.h"


class GameObject;

class Game
{
public:
	Game();
	
	void Update(float dt);
	void Draw(sf::RenderWindow* window);
	void AddObject(std::shared_ptr<GameObject> object);

	void PushState(std::unique_ptr<State::Game_State> state);
	void PopState();
	void ChangeState(std::unique_ptr<State::Game_State> state);

	void QuickSort(int left, int right);

private:
	std::vector<std::shared_ptr<GameObject>> m_gameObjects;
	std::stack<std::unique_ptr<State::Game_State>> m_states;
	
};

