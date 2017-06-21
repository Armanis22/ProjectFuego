#include "stdafx.h"
#include "Random.h"

namespace Random
{
	std::minstd_rand generater;

	void init()
	{
		generater.seed(static_cast<unsigned int>(time(NULL)));
	}

	int intInRange(int low, int high)
	{
		std::uniform_int_distribution<int> distribution(low, high);
		return distribution(generater);
	}

	float floatInRange(float low, float high)
	{
		std::uniform_real_distribution<float> distribution(low, high);
		return distribution(generater);
	}


}