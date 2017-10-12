#pragma once
#include <iostream>
#include "Stat.h"

//Food will likely inherit from a base item class of some sort, build this out for monster consumption,
// TODO: later make a better base to handle any needed item

enum class Rarity
{
	Common,
	Uncommon,
	Rare
};

class Food
{
public:
	Food();
	~Food();

	std::string GetStatName() { return m_whichStatToIncrease; }
	float GetIncreaseAmount() { return m_amountToIncrease; }
	float GetFillAmount() { return m_fillAmount; }

private:
	std::string m_name;
	std::string m_whichStatToIncrease; //name of the stat we want to increase
	Rarity m_rarity; //this will handle either larger stat gains or multiple
	float m_amountToIncrease; // for now items will just increase one specific stat
	float m_fillAmount; //this number will increase the hunger gauge of the monster, when its full the monster can't be fed
};

