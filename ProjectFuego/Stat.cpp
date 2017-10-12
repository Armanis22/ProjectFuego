#include "Stat.h"

Stat::Stat(std::string id, float current, float max) : m_id(id), m_current(current), m_max(max)
{
	if (current > max)
		m_current = m_max;
}

void Stat::SubtractCurrent(float val)
{
	m_current -= val;

	if (m_current < 0)
	{
		m_current = 0.f;
	}
}

void Stat::AddCurrent(float val)
{
	m_current += val;

	if (m_current > m_max)
	{
		m_current = m_max;
	}
}

void Stat::MultiplyCurrent(float val)
{
	m_current *= val;
}

void Stat::DivideCurrent(float val)
{
	m_current /= val;

	if (m_current < 0)
	{
		m_current = 0.f;
	}
}
