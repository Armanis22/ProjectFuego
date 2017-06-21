#pragma once
#include <SFML\Graphics.hpp>
#include <map>

#include "ResourceManager.h"

enum class FontName
{

};

class FontManager : public ResourceManager<FontName, sf::Font>
{
public:
	FontManager()
	{

	}

};
