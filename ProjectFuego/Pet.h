#pragma once
#include "Stat.h"
#include <vector>
#include "CharacterObject.h"

enum class Type
{
	NORMAL, //base monster, regular attributes (starter)
	FIGHTING, // Attack
	FIRE, // Attack / elemental
	ROCK, // Defensive
	ICE, // Defensive / elemental
	SHADOW, // Speed / attack
	COUNT // Holds the length of the types, more can be added / removed as needed
};

class Monster : public CharacterObject
{
public:
	Monster(sf::Vector2f pos);
	~Monster();

	void RollBaseStats(); //loop for stat init
	void InitializeStat(int statNum); //For setting stat (Str, Def, etc) pass in number for a switch to create a stat

	std::string GetMonsterType(Type monsterType);

	void Eat(std::string statToBeModified, float statIncrease, float hungerIncrease); // Feed monster to increase stats
	void Evolve(); // Current idea is once 

	bool IsHungry();
	bool CanEvolve() { return m_evolveState; }

	void ListStats();

private:
	std::vector<Stat*> m_attributes;
	Type m_monsterType; //all monsters will start at NORMAL for now, maybe an option to buy a monster of a specific type later.

	Stat* m_hunger;
	bool m_evolveState;
};

