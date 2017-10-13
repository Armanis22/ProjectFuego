#pragma once
#include <SFML\Graphics.hpp>
#include <map>

#include "ResourceManager.h"


enum class TextureName
{
		CHARACTERONE,
		SKELETON
};

class TextureManager : public ResourceManager<TextureName, sf::Texture>
{
public:
	TextureManager()
	{
		addResource(TextureName::CHARACTERONE, "Assets/CharSprites/characterone.png");
		addResource(TextureName::SKELETON, "Assets/CharSprites/skeleton.png");

	}
};