#include "stdafx.h"
#include "InputHolder.h"

InputManager & InputManager::Instance()
{
	static InputManager inputManager;
	return inputManager;
}

void InputManager::StoreKeyPressed(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (keys.count(event.key.code) == 0)
		{
			keys[event.key.code] = true;
		}
	}
	if (event.type == sf::Event::KeyReleased)
	{
		if (keys.count(event.key.code) == 1)
		{
			keys.erase(event.key.code);
		}
	}
}

const std::unordered_map<int, bool>& InputManager::GetKeysPressed() const
{
	return keys;
}



 const size_t InputManager::GetNumberOfKeys() const
 {
	 return keys.size();
 }
