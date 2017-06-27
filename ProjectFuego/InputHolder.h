#pragma once
#include <unordered_map>
#include "SFML\Graphics.hpp"

struct InputManager
{
public:
	static InputManager& Instance();

	void	StoreKeyPressed			(sf::Event& event);
	const	size_t GetNumberOfKeys	()	const;

	const	std::unordered_map<int,bool>&	GetKeysPressed()	const;

private:
	std::unordered_map<int, bool> keys;
};