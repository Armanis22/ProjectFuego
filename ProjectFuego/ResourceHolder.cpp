#include "stdafx.h"
#include "ResourceHolder.h"

const ResourceHolder & ResourceHolder::Instance()
{
	static ResourceHolder resourceHolder;
	return resourceHolder;

}

const sf::Texture & ResourceHolder::getTexture(TextureName name) const
{
	return textures.get(name);
}
const sf::SoundBuffer & ResourceHolder::getSoundBuffer(SoundName name) const
{
	return sounds.get(name);
}
const sf::Font & ResourceHolder::getFont(FontName name) const
{
	return fonts.get(name);
}
