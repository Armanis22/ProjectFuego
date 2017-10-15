#pragma once

#include <memory>
#include "SFML\Graphics.hpp"

struct MouseManager
{
public:
	static MouseManager& Instance();

	void Init(sf::RenderWindow& window);


	const bool IsMouseRightPressed() const;
	const sf::Vector2f MousePosition() const;

private:
	sf::RenderWindow* pmWindow;

};


