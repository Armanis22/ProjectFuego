#pragma once
#include <unordered_map>
#include "SFML\Graphics.hpp"
#include <iostream>

struct InputManager
{
public:
	static InputManager& Instance();

	void	StoreKeyPressed			(sf::Event& event);
	void	GetKeysPressed			(int index)			const;
	const	size_t GetNumberOfKeys	()					const;

private:
	std::unordered_map<int, bool> keys;
};