#pragma once

#include "TextureManager.h"
#include "FontManager.h"
#include "SoundManager.h"

struct ResourceHolder
{
public:
	static const ResourceHolder& Instance();

	const sf::Texture&		getTexture		(TextureName name)	const;
	const sf::SoundBuffer&	getSoundBuffer	(SoundName name)	const;
	const sf::Font&			getFont			(FontName name)		const;

private:
	TextureManager	textures;
	SoundManager	sounds;
	FontManager		fonts;

};