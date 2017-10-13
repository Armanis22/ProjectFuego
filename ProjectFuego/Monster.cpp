#include "stdafx.h"
#include "Monster.h"
#include <iostream>



Monster::Monster() : m_evolveState(false), m_hunger(0)
{
	//Begin by initializing the base stats
	RollBaseStats();
	m_monsterType = Type::NORMAL; //change this later, if we want to take a specific type (Alternate constructor maybe)
	m_hunger = new Stat("Hunger", 0, 20); 
}


Monster::~Monster()
{
	//Delete the stats vector
	for (unsigned int i = 0; i < m_attributes.size(); i++)
	{
		delete m_attributes[i];
	}

	//Clean any other necessary things
}

void Monster::RollBaseStats()
{
	//Function to roll stats and load into the attribute vector

	for (int i = 1; i < 7; i++)
	{
		InitializeStat(i);
	}
}

void Monster::InitializeStat(int statNum)
{
	//Helper for stat initializing for loop, pass in i which will hit the switch statement
	Stat* tmp;
	
	switch (statNum)
	{
	case 1:
		tmp = new Stat("Hp", 5, 5);
		m_attributes.push_back(tmp);
		break;
	case 2:
		tmp = new Stat("Mp", 5, 5);
		m_attributes.push_back(tmp);
		break;
	case 3:
		tmp = new Stat("Str", 5, 5);
		m_attributes.push_back(tmp);
		break;
	case 4:
		tmp = new Stat("Def", 5, 5);
		m_attributes.push_back(tmp);
		break;
	case 5:
		tmp = new Stat("Mag", 5, 5);
		m_attributes.push_back(tmp);
		break;
	case 6:
		tmp = new Stat("Spd", 5, 5);
		m_attributes.push_back(tmp);
		break;
	default:
		std::cout << "Invalid stat count!" << std::endl;
		break;
	}
}

std::string Monster::GetMonsterType(Type monsterType)
{
	std::string type;
	
	switch (monsterType)
	{
	case Type::NORMAL:
		type = "Normal";
		break;
	case Type::FIGHTING:
		type = "Fighting";
		break;
	case Type::FIRE:
		type = "Fire";
		break;
	case Type::ICE:
		type = "Ice";
		break;
	case Type::ROCK:
		type = "Rock";
		break;
	case Type::SHADOW:
		type = "Shadow";
		break;
	}
	return type;
}

void Monster::Eat(std::string statToBeModified, float statIncrease, float hungerIncrease)
{
	//Feed the monster food to increase targeted attributes

	for (int i = 0; i < m_attributes.size(); i++)
	{
		if (m_attributes[i]->GetID() == statToBeModified)
		{
			m_attributes[i]->AddMax(statIncrease);
			m_attributes[i]->SetStatToMax();

			if (m_attributes[i]->GetMax() > 10.0f)
			{
				m_evolveState = true;
			}
		}
	}

	m_hunger->AddCurrent(hungerIncrease);
}

void Monster::Evolve()
{
	//Monster has hit the requirement to change types
	m_evolveState = false;

	//Need to determine a good way to check the stat thats hit a mark, to decide what the new type is without some stupid switch statment

	std::cout << "Monster has evolved!" << std::endl;
	std::cout << "It's new type is: " << GetMonsterType(m_monsterType) << "\n" << std::endl;
}

bool Monster::IsHungry()
{
	//may want more explicit checking, (if someone tries to feed a large fillamount, we want to case so they don't get more increase than they should before the fill)
	if (m_hunger->GetCurrent() == m_hunger->GetMax())
	{
		return false;
	}

	return true;
}

void Monster::ListStats()
{
	//Print the monsters stats to the screen for reference

	std::cout << "Monster Type: " << GetMonsterType(m_monsterType) << "\n" << std::endl;

	for (unsigned int i = 0; i < m_attributes.size(); i++)
	{
		Stat* stat = m_attributes[i];
		std::cout << stat->GetID() << ": " << stat->GetCurrent() << "/" << stat->GetMax() << "\n" << std::endl;
	}

	std::cout << m_hunger->GetID() << ": " << m_hunger->GetCurrent() << "/" << m_hunger->GetMax() << "\n" << std::endl;
}