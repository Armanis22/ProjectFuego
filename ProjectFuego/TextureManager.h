#pragma once
#include <SFML\Graphics.hpp>
#include <map>

#include "ResourceManager.h"


enum class TextureName
{
		CHARACTERONE
};

class TextureManager : public ResourceManager<TextureName, sf::Texture>
{
public:
	TextureManager()
	{
		addResource(TextureName::CHARACTERONE, "Assets/Textures/characterone.png");

	}
};