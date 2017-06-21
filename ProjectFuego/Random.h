#pragma once
#include <random> 
#include <ctime>

namespace Random
{
	void init();
	int intInRange(int low, int high);
	float floatInRange(float low, float high);

}