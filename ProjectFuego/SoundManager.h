#pragma once
#include <SFML\Audio.hpp>
#include <map>

#include "ResourceManager.h"

enum class SoundName
{

};

class SoundManager : public ResourceManager<SoundName, sf::SoundBuffer>
{
public:
	SoundManager()
	{
	
	}
};