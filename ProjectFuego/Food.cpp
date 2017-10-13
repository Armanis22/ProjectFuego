#include "stdafx.h"
#include "Food.h"

Food::Food() : m_rarity(Rarity::Common), m_fillAmount(1.0f), m_amountToIncrease(1.0f)
{
	// Make a function to roll a food, these will be stocked in stores/found around... 'placeholder food' at the moment
	m_name = "Food"; 
	m_whichStatToIncrease = "Str";
}

Food::~Food()
{
}
