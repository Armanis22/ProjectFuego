#include "stdafx.h"
#include "MouseManager.h"

MouseManager & MouseManager::Instance()
{
	static MouseManager mouseManager;
	return mouseManager;
}

void MouseManager::Init(sf::RenderWindow & window)
{
	pmWindow = &window;
}

const bool MouseManager::IsMouseRightPressed() const
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		return false;
	}
	else
	{
		return true;
	}
}

const sf::Vector2f MouseManager::MousePosition() const
{
	return static_cast<sf::Vector2f>(sf::Mouse::getPosition(*pmWindow));
}
