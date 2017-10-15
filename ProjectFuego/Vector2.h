#pragma once

#include "SFML\Graphics.hpp"


// just using a namespace for now to differentiate these from the SFML vector stuff
namespace Vector2
{
	inline void Normalize(sf::Vector2f& vec);
	inline double Length(sf::Vector2f lhs);





	// CAREFUL with this one, normalizes the vector you feed it

	void Normalize(sf::Vector2f& vec)
	{
		double len = Length(vec);
		vec.x /= len;
		vec.y /= len;
	}

	double Length(sf::Vector2f vec)
	{
		return sqrtf(vec.x*vec.x + vec.y*vec.y);
	}
}
