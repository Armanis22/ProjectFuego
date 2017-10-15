#pragma once

#include "SFML\Graphics.hpp"


// just using a namespace for now to differentiate these from the SFML vector stuff
namespace Vector2
{
	inline sf::Vector2f Normalize(sf::Vector2f& vec);
	inline double Length(sf::Vector2f lhs);
	inline float LengthSq(sf::Vector2f vec);
	inline sf::Vector2f Perp(sf::Vector2f vec);

	//Zero out the passed in vector
	inline sf::Vector2f Zero(sf::Vector2f vec) { return sf::Vector2f(vec.x = 0.f, vec.y = 0.f); }
	
	inline void Truncate(sf::Vector2f vec, float max);





	// CAREFUL with this one, normalizes the vector you feed it
	// Modded to return a vector
	sf::Vector2f Normalize(sf::Vector2f& vec)
	{
		sf::Vector2f v = vec;
		double len = Length(vec);
		vec.x /= len;
		vec.y /= len;

		return v;
	}

	double Length(sf::Vector2f vec)
	{
		return sqrtf(vec.x*vec.x + vec.y*vec.y);
	}

	float LengthSq(sf::Vector2f vec)
	{
		return (vec.x * vec.x + vec.y * vec.y);
	}

	//Returns the side vector (used for the heading vector)
	sf::Vector2f Perp(sf::Vector2f vec)
	{
		return sf::Vector2f(-vec.y,vec.x);
	}

	void Truncate(sf::Vector2f vec, float max)
	{
		if (Length(vec) > max)
		{
			Normalize(vec);

			vec *= max;
		}
	}
}
